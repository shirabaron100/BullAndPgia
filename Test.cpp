/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
		;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=100, true);  // smarty should always win in at most 10 turns!
		}
		//our tests/////////////////////////
		testcase.setname("Calculate bull and pgia-our test");

		ConstantChooser c2134{"2134"}, cnon{""}, a9999{"9999"};
		ConstantGuesser g1111{"1111"}, gnon{""}, g999999{"999999"};

		testcase.CHECK_OUTPUT(calculateBullAndPgia("2134","1111"), "1,0");
  		testcase.CHECK_OUTPUT(calculateBullAndPgia("",""), "1,0");
  		testcase.CHECK_OUTPUT(calculateBullAndPgia("9999","999999"), "0,0");
  		testcase.CHECK_OUTPUT(calculateBullAndPgia("99999999","99"), "0,0");
		testcase.CHECK_EQUAL(play(c2134, g1234, 4, 100), 1);      
		testcase.CHECK_EQUAL(play(cnon, gnon, 4, 100), 101);   
		testcase.CHECK_EQUAL(play(a9999,  g1111, 4, 100), 101);   
		testcase.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0); 

		//tests in differnet length
  		testcase.CHECK_OUTPUT(calculateBullAndPgia("198722","123987"), "1,4");
  		testcase.CHECK_OUTPUT(calculateBullAndPgia("555555","554555"), "5,0");
  		testcase.CHECK_OUTPUT(calculateBullAndPgia("123456789","123456789"), "9,0");
	    testcase.CHECK_OUTPUT(calculateBullAndPgia("7897","7789"), "1,3");
        testcase.CHECK_OUTPUT(calculateBullAndPgia("12","12"), "2,0");
		testcase.CHECK_OUTPUT(calculateBullAndPgia("165454","165454"), "6,0");
		testcase.CHECK_OUTPUT(calculateBullAndPgia("656","222"), "0,0");
		testcase.CHECK_OUTPUT(calculateBullAndPgia("012","013"), "2,0");
		testcase.CHECK_OUTPUT(calculateBullAndPgia("9992345","9923459"), "2,5");
		testcase.CHECK_OUTPUT(calculateBullAndPgia("121211","121211"), "6,0");
		testcase.CHECK_OUTPUT(calculateBullAndPgia("00","00"), "2,0");

		//testing the randomGusser
  		RandomChooser randy1;
		RandomGuesser randy2;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_OK(play(randy1, randy2, 4, 100)); 
		}
		//testing differents legth with the smarty
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 3, 100)<=100, true);  // smarty should always win in at most 10 turns!
		}
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 2, 100)<=100, true);  // smarty should always win in at most 10 turns!
		}
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 1, 100)<=100, true);  // smarty should always win in at most 10 turns!
		}
    	grade = testcase.grade();
		} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}