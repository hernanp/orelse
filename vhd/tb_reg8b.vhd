library ieee;
use ieee.std_logic_1164.all;

entity tb_reg8b is
end tb_reg8b;

architecture tb of tb_reg8b is

  component reg8b
    port (ld    : in std_logic;
          clk   : in std_logic;
          d_in  : in std_logic_vector (7 downto 0);
          d_out : out std_logic_vector (7 downto 0));
  end component;

  signal ld    : std_logic;
  signal clk   : std_logic;
  signal d_in  : std_logic_vector (7 downto 0);
  signal d_out : std_logic_vector (7 downto 0);

  constant TbPeriod : time := 10 fs; -- EDIT Put right period here
  signal TbClock : std_logic := '0';
  signal TbSimEnded : std_logic := '0';

begin

  dut : reg8b
    port map (ld    => ld,
              clk   => clk,
              d_in  => d_in,
              d_out => d_out);

  -- Clock generation, starts at 0
  TbClock <= not TbClock after TbPeriod/2 when TbSimEnded /= '1' else '0';

  clk <= TbClock;

  stimuli : process
  begin
    ld <= '0';
    d_in <= (others => '0');

    -- Reset generation
    --  as I haven't guessed it
    wait for 20 fs;
    ld <= '1';
    wait for 10 fs;
    d_in <= (others => '1');
    wait for 5 fs;
    ld <= '0';
    wait for 10 fs;
    d_in <= (others => '0');
    wait for 30 fs;
    d_in <= (others => '1');
    wait for 10 fs;
    ld <= '1';
    wait for 50 fs;
    
    -- EDIT Add stimuli here
    --wait for 10 * TbPeriod;

    -- Stop the clock and hence terminate the simulation
    TbSimEnded <= '1';
    wait;
  end process;

end tb;

-- Configuration block below is required by some simulators. Usually no need to
-- edit.

configuration cfg_tb_reg8b of tb_reg8b is
  for tb
end for;
end cfg_tb_reg8b;
