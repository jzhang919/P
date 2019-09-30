import java.util.List;

/**
 * A TestManager objects managers all the test runners deployed within a given directory.
 * It manages all the test runners and their associated test validators for the specified
 * suite of tests.
 */
public interface TestManager {
    /**
     * Adds a runner to the manager.
     * @param runner a specified test runner with a collection of test validators.
     */
    void addRunner(TestRunner runner);

    /**
     * Adds a P-Sharp program to be tested under the test manager.
     * @param program
     */
    void addProgram(Program program);

    /**
     * Returns all the current P-Sharp programs to be tested/managed under the current test manager.
     * @return all the P-Sharp Program objects associated with this particular test manager object.
     */
    List<Program> getAllPrograms();

    /**
     * Spawns a new test runner and adds the program to apply the runner under it.
     * @param program the program to add the new test runner to.
     * @return the test runner that is created.
     */
    TestRunner spawnTestRunner(Program program);

    /**
     * Returns all the test runners associated with the given program.
     * @param program the P-Sharp program to search within.
     * @return the list of all test runners for the specified program.
     */
    List<TestRunner> getAllTestRunners(Program program);

    /**
     * Returns all the programs associated with the given test runner.
     * @param runner the test runner to search within.
     * @return the list of all test programs for the specified runner.
     */
    List<TestRunner> getAllTestPrograms(TestRunner runner);
}
