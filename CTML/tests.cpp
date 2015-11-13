#include "CTML.h"

// tests if two strings are equivelent to each other
const bool assert_strings_equal(const std::string& left, const std::string& right) {
	return (left == right);
}

// this test ensures that HTML inside of the content is escaped correctly.
void run_escape_test() {
	// what the node's to string should be equal to
	const std::string htmlString = "<a class=\"button\">&lt;script&gt;alert(\"ha ha hacked!\")&lt;/script&gt;</a>";
	CTML::Node node("a.button", "<script>alert(\"ha ha hacked!\")</script>");
	// the node's string output
	const std::string nodeString = node.ToString(CTML::SINGLE_LINE, 0);
	bool test = assert_strings_equal(htmlString, nodeString);
	std::cout << "Escape Test " << ((test) ? "passed!" : "failed!") << std::endl <<
		"HTML Output: " << nodeString << std::endl <<
		// use a double end line at the end for spacing between tests
		"Expected Output: " << htmlString << std::endl << std::endl;
}

// this test ensures that the HTML document created is equal to a correct HTML5 document
void run_document_test() {
	// what the document's to string should be equal to
	const std::string htmlString = "<!DOCTYPE html><html><head></head><body><h1>&lt;test!&gt;</h1></body></html>";
	CTML::Document doc;
	// the string output of the document
	doc.AddNodeToBody(CTML::Node("h1", "<test!>"));
	const std::string docString = doc.ToString(CTML::SINGLE_LINE);
	bool test = assert_strings_equal(htmlString, docString);
	std::cout << "Document Test " << ((test) ? "passed!" : "failed!") << std::endl <<
		"HTML Output: " << docString << std::endl <<
		// use a double end line at the end for spacing between tests
		"Expected Output: " << htmlString << std::endl << std::endl;
}

// this test checks if the classes provided are correctly stored
void run_class_test() {
	const std::string classString = "test classes are fun";
	CTML::Node testNode("a#test.test.classes.are.fun");
	// get the test node's classlist.
	const std::string classList = testNode.GetAttribute("class");
	bool test = assert_strings_equal(classString, classList);
	std::cout << "Class Test " << ((test) ? "passed!" : "failed!") << std::endl <<
		"Class Output: " << classList << std::endl <<
		// use a double end line at the end for spacing between tests
		"Expected Output: " << classString << std::endl << std::endl;
}

// this test checks if the attributes provided are correctly stored and gotten
void run_attribute_test() {
	const std::string attrOutput = "testAttr1";
	const std::string attr2Output = "testAttr2";
	const std::string attr3Output = "";
	CTML::Node testNode("a");
	// set two attributes on the node
	testNode.SetAttribute("attr1", "testAttr1").SetAttribute("attr2", "testAttr2");
	// get each attribute's output
	const std::string attrOut = testNode.GetAttribute("attr1");
	const std::string attr2Out = testNode.GetAttribute("attr2");
	const std::string attr3Out = testNode.GetAttribute("attr3");
	// test each string
	bool test1 = assert_strings_equal(attrOutput, attrOut);
	bool test2 = assert_strings_equal(attr2Output, attr2Out);
	bool test3 = assert_strings_equal(attr3Output, attr3Out);
	std::cout << "Class Test " << ((test1 && test2 && test3) ? "passed!" : "failed!") << std::endl <<
		"Attr 1 Output: " << attrOut << std::endl <<
		"Expected Output: " << attrOutput << std::endl <<
		"Attr 2 Output: " << attr2Out << std::endl <<
		"Expected Output: " << attr2Output << std::endl <<
		"Attr 3 Output: " << attr3Out << std::endl <<
		// use a double end line at the end for spacing between tests
		"Expected Output: " << attr3Output << std::endl << std::endl;

}

int main() {
	run_escape_test();
	run_document_test();
	run_class_test();
	run_attribute_test();
	return 0;
}