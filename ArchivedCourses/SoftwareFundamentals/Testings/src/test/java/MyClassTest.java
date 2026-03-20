import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class MyClassTest {

    MyClass calculator = new MyClass();

    @Test
    void testCorrectAddition() {
        int result = calculator.add(2, 3);
        assertEquals(5, result);
    }


    @Test
    void testIncorrectAdd() {
        int res = calculator.add(1, 2); // 3
        assertNotEquals(3, res); // -> true
    }
}

