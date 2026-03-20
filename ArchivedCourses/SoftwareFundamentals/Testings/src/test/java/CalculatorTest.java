import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

//test suite: many test cases
public class CalculatorTest {

    MyCalculator myCalculator = new MyCalculator();

//    independent test case
    @Test
    void testAdd() {
        int res = myCalculator.add(1, 2);
        assertEquals(3, res); // true
    }

    @Test
    void testAddNotEqual() {
        assertNotEquals(4, myCalculator.add(1, 2)); // true
    }
}
