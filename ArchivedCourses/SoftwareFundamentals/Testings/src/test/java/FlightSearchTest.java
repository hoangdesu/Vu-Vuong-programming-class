import flight.FlightSearch;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class FlightSearchTest {
    FlightSearch flightSearch = new FlightSearch();

    @Test
    void testValidTotalPassengers() {
//        boolean s1 = flightSearch.runFlightSearch(
//                "",
//                "doh",
//                true,
//                "",
//                "mel",
//                "economy",
//                1,
//                2,
//                1
//        );

//        assertEquals(true, s1);
        assertTrue(flightSearch.runFlightSearch(
                "",
                "doh",
                true,
                "",
                "mel",
                "economy",
                1,
                2,
                1
        ));
    }


    @Test
    void testInvalidTotalPassengers() {
        assertFalse(flightSearch.runFlightSearch(
                "",
                "doh",
                true,
                "",
                "mel",
                "economy",
                1,
                2,
                8
        ));
    }

    @Test
    void testInvalidDepartureAirportCode() {
        assertFalse(flightSearch.runFlightSearch(
                "",
                "han",
                true,
                "",
                "mel",
                "economy",
                1,
                2,
                0
        ));
    }

    @Test
    void testInvalidReturnDateWithWrongLeapYear() {

    }

}
