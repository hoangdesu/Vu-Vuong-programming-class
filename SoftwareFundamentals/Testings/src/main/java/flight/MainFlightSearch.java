package flight;

public class MainFlightSearch {
    public static void main(String[] args) {
        FlightSearch flightSearch = new FlightSearch();

        boolean search1 = flightSearch.runFlightSearch(
                "",
                "doh",
                true,
                "",
                "mel",
                "economy",
                1,
                2,
                1
        );

        System.out.println(search1);


    }
}
