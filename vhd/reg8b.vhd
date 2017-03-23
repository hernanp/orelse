library ieee;
use ieee.std_logic_1164.all;

entity reg8b is
  port(ld,clk: in std_logic;
       d_in: in std_logic_vector(7 downto 0);
       d_out: out std_logic_vector(7 downto 0));
end reg8b;

architecture my_reg of reg8b is
begin
  process(clk,ld)
  begin
    if(ld='1' and rising_edge(clk)) then
      d_out <= d_in;
    end if;
  end process;
end my_reg;
