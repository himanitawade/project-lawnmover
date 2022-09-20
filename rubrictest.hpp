///////////////////////////////////////////////////////////////////////////////
// rubrictest.hpp
//
// minimalist C++ unit testing for grading rubric-based programming assignments
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cassert>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

// As an end user, you really only need to pay attention to the
// Rubric class and TEST_... macros, below.

// A test throws TestFailureException to signal when a test fails.
class TestFailureException {
public:
  // line is source code line, probably from __LINE__;
  // file is source code filename, probably from __FILE__; and
  // message is a brief decription of the test case.
  TestFailureException(int line,
		       const std::string file,
		       const std::string& message)
    : _line(line),
      _file(file),
      _message(message) { }

  int line() const { return _line; }
  const std::string& file() const { return _file; }
  const std::string& message() const { return _message; }

private:
  int _line;
  const std::string _file, _message;
};

// A RubricCriterion is one criterion (row) in a rubric. It carries a
// number of points, and has a unit test function. When the function
// is run and all tests pass (no exceptions), the student earns the
// full points for the criterion. Otherwise (some test fails and
// throws an exception), the studen earns zero points for this
// criterion.
class RubricCriterion {
public:
  // name is a human-readable name;
  // points is the positive number of points awarded for this criterion; and
  // test is a function that takes no arguments and returns void, and
  // should perform a number of unit tests using the TEST_... macros
  // below.
  RubricCriterion(const std::string& name,
		  int points,
		  std::function<void()> test)
    : _name(name),
      _points(points),
      _test(test)
  { assert(points > 0); }

  // Accessors.
  const std::string& name() const { return _name; }
  int points() const { return _points; }
  const std::function<void()>& test() const { return _test; }

private:
  std::string _name;
  int _points;
  std::function<void()> _test;
};

// A rubric represents a mult-critera grading scheme. It collects
// several RubricCriterion objects.
class Rubric {
public:
  // Create an empty rubric with no criteria.
  Rubric() { }

  // Add a criterion with the given name, points, and test function.
  void criterion(const std::string& name,
		 int points,
		 std::function<void()> test) {
    _criteria.push_back(RubricCriterion(name, points, test));
  }

  // The main event: run all the tests, score all the criteria, and
  // print out the results, including total score. Returns 0 when all
  // tests pass, or 1 otherwise; this return value is suitable for the
  // return value of main() in a unit-test program.
  int run() {

    int earned_points(0), total_points(0);
    bool all_passed(true);

    for ( auto& criterion : _criteria ) {

      std::cout << criterion.name() << ": ";

      try {

	// run this criterion's test function
	criterion.test()();

	// if that function call threw an exception, we never reach these lines
	std::cout << "passed, score "
		  <<  criterion.points() << "/" << criterion.points()
		  << std::endl;

	earned_points += criterion.points();

      } catch (TestFailureException e) {

	// test function threw an exception; test failed
	std::cout << std::endl
		  << "    TEST FAILED: " << std::endl
		  << "    line " << e.line()
		  << " of file " << e.file()
		  << ", message: " << e.message()
		  << std::endl
		  << "    score 0/" << criterion.points()
		  << std::endl;

	all_passed = false;
      }

      total_points += criterion.points();
    }

    // print summary score
    std::cout << "TOTAL SCORE = "
	      << earned_points << " / " << total_points
	      << std::endl
	      << std::endl;

    if (all_passed) {
      return 0;
    } else {
      return 1;
    }
  }

private:
  std::vector<RubricCriterion> _criteria;
};

// Test macros. The test function passed to Rubric::criterion(...)
// should invoke these macros to test whether the student code is
// working. Each macro throws a TestFailureException when a test
// fails.

// Always signal that a test failed. This macro is intended to be used
// by the other macros below, and can also be used when the test
// function reaches a statement that should be unreachable in correct
// code.
#define TEST_FAIL(message) \
  throw TestFailureException(__LINE__, __FILE__, std::string(message))

// Expects the expression (expr) to be false.
#define TEST_FALSE(message, expr) \
  { if (expr) { TEST_FAIL(message); } }

// Expects the expression (expr) to be true.
#define TEST_TRUE(message, expr) \
  TEST_FALSE(message, ! (expr) )

// Expects (x) == (y).
#define TEST_EQUAL(message, x, y) \
  TEST_TRUE(message, (x) == (y))

// Expects (x) != (y).
#define TEST_NOT_EQUAL(message, x, y) \
  TEST_TRUE(message, (x) != (y))

// Expects (x) > (y).
#define TEST_GT(message, x, y) \
  TEST_TRUE(message, (x) > (y))

// Expects (x) >= (y).
#define TEST_GE(message, x, y) \
  TEST_TRUE(message, (x) >= (y))

// Expects (x) < (y).
#define TEST_LT(message, x, y) \
  TEST_TRUE(message, (x) < (y))

// Expects (x) <= (y).
#define TEST_LE(message, x, y) \
  TEST_TRUE(message, (x) <= (y))

///////////////////////////////////////////////////////////////////////////////
// rubrictest.hh
///////////////////////////////////////////////////////////////////////////////
