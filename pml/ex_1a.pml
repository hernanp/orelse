/* example channels */
/* http://spinroot.com/spin/Doc/Exercises.pdf ex.1a */

chan comm = [0] of {bool, bool, bool};

init {
	byte i = 0;
	do
	:: i = i+1
	od;
  atomic{
    run p1();
    run p2();
  }
}

proctype p1(){
  atomic{
    comm!true, true, true;
  }
}

proctype p2(){
  bool b1,b2,b3;
  atomic{
    comm?b1,b2,b3;
  }
}

