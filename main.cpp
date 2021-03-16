#include "snowman.cpp"

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	cout << ariel::snowman(11114411) << endl;   /* Should print:
_===_
(.,.)
( : )
( : )
	*/
	cout << ariel::snowman(12222222) << endl;   /* Should print:
 _===_
\(o.o)/
 (] [)
 (" ")
	*/
	cout << ariel::snowman(33232124) << endl;   /* Should print:
   _
  /_\
\(o_O)
 (] [)>
 (   )
	*/
	cout << ariel::snowman(33333333) << endl;   /* Should print:
   _
  /_\
 (O_O)
/(> <)\
 (___)
	*/
	cout << ariel::snowman(12341234) << endl;   /* Should print:
 _===_
 (O.-)/
<(> <)
 (   )
	*/
	cout << ariel::snowman(43214321) << endl;   /* Should print:
  ___
 (_*_)
 (o_.)
 (] [)\
 ( : )
	*/
	
	try {
		cout << ariel::snowman(5) << endl;   // Exception - not a valid code
	} catch (string massage) {
	 	cout << "   caught exception: " << massage << endl;  // should print "The number does not exist"
	}
	
	try {
		cout << ariel::snowman(-12341234) << endl;   // Exception - not a valid code
	} catch (string massage) {
	 	cout << "   caught exception: " << massage << endl;  // should print "The number cannot be a minus"
	}
	
	try {
		cout << ariel::snowman(123412341) << endl;   // Exception - not a valid code
	} catch (string massage) {
	 	cout << "   caught exception: " << massage << endl;  // should print "There are more than 8 numbers"
	}
}