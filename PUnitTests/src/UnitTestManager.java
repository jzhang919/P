import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public abstract class UnitTestManager implements TestManager{

    private HashMap<TestRunner, List<Program>> _programsByRunners;
    private List<Program> _programs;

    UnitTestManager() {
        _programsByRunners = new HashMap<>();
    }

    @Override
    public void addRunner(TestRunner runner) {
        if (_programsByRunners.containsKey(runner)) {
            return;
        }
        _programsByRunners.put(runner, new ArrayList<>());
    }

    @Override
    public void addProgram(Program program) {
        if (_programs.contains(program)) {
            return;
        }
        _programs.add(program);
    }

    @Override
    public List<Program> getAllPrograms() {
        return _programs;
    }


}
