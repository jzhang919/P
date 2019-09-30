/**
 * A test validator class performs a variety of required assertions and validations on the
 * given P-Sharp programs. Each validator is associated with at least one P-Sharp programs, and
 * belongs to exactly one test runner.
 */
public interface TestValidator {
    /**
     * Asserts if the actual output produced by the P-Sharp Program matches with the expected output
     * @param actual the actual output string.
     * @param expected the expected output string.
     * @return true if matches; false otherwise
     */
    boolean validate(String actual, String expected);

    /**
     * Asserts if the given P-Sharp program compile successfully without any syntax error, type check error, etc.
     * @param program the program to assert.
     * @return true if no compile-time exceptions; false otherwise
     */
    boolean staticAssert(Program program);

    /**
     * Asserts if the given P-Sharp program runs and passes all the specified validations (correct output)
     * @param program the program to assert.
     * @return true if no run-time exceptions; false otherwise
     */
    boolean dynamicAssert(Program program);
}
