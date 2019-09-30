import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public abstract class UnitTestRunner implements TestRunner {
    private List<Program> _programs;
    private HashMap<Program, List<TestValidator>> _validatorsByPrograms;

    UnitTestRunner(Program program) {
        _programs = new ArrayList<>();
        _validatorsByPrograms = new HashMap<>();
        _programs.add(program);
    }

    @Override
    public void addValidator(TestValidator validator, Program program) {
        if (!_validatorsByPrograms.containsKey(program)) {
            _validatorsByPrograms.put(program, new ArrayList<>());
        }
        _validatorsByPrograms.get(program).add(validator);
    }
}
