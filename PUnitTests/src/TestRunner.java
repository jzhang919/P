import java.util.List;

/**
 * A runner class compiles and executes the given P-Sharp Program, writes the output into the specified path,
 * and applies a TestValidator to assert certain given test cases. A test runner can own many test validators.
 */
public interface TestRunner {

    /**
     * compiles the program it is currently under and writes to the given output path specified by the string argument.
     * If the specified path/file doesn’t exist, create the given file and then write to it.
     * @param outputPath the path to the output file
     */
    void compileAndWrite(String outputPath);

    /**
     * compiles the specified list of P-Sharp programs and writes the output to the specified path.
     * @param programs the list of programs.
     * @param outputPath the path to the output file.
     */
    void compileAndWrite(List<Program> programs, String outputPath);

    /**
     * adds a validator to the current runner.
     * @param validator the validator to be added.
     * @param program the program to add the validator under.
     */
    void addValidator(TestValidator validator, Program program);

    /**
     * returns all the test validators associated with the given test runner.
     * @return all test validators
     */
    List<TestValidator> getAllValidators();
}
