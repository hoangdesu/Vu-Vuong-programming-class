package flight;

public class MainFlightSearch {
    public static void main(String[] args) {
        FlightSearch flightSearch = new FlightSearch();

        boolean search1 = flightSearch.runFlightSearch(
                "01/11/2025",
                "doh",
                false,
                "29/02/2028",
                "mel",
                "economy",
                1,
                2,
                1
        );

        System.out.println(search1);

    }
}
