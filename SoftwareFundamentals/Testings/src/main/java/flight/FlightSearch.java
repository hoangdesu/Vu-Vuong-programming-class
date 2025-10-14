//package flight;
//
//import java.util.Set;
//
//public class FlightSearch {
//   private String  departureDate;
//   private String  departureAirportCode;
//   private boolean emergencyRowSeating;
//   private String  returnDate;
//   private String  destinationAirportCode;
//   private String  seatingClass;
//   private int     adultPassengerCount;
//   private int     childPassengerCount;
//   private int     infantPassengerCount;
//
//
//   public boolean runFlightSearch(String departureDate,
//                                  String departureAirportCode,
//                                  boolean emergencyRowSeating,
//                                  String returnDate,
//                                  String destinationAirportCode,
//                                  String seatingClass,            // "economy", "premium economy", "business", "first"
//                                  int adultPassengerCount,
//                                  int childPassengerCount,
//                                  int infantPassengerCount
//   ) {
//
//      //TODO: Validate all the provided parameters.
//      //if the search parameters meets the given conditions,
//      //   the function should initialise all the class attributes and return true.
//      //else
//      //   the function should return false
//
////      Guard clause
//
////      Condition 1. The total number of passenger per search must be at least 1 and cannot exceed 9.
//      int totalPassengers = adultPassengerCount + childPassengerCount + infantPassengerCount;
//      if (totalPassengers < 1 || totalPassengers > 9) return false;
//
//
////      Condition 2. Children cannot be seated in emergency row seating or first class.
////      ...
//
//
//
//
//
////      Condition 9. The seating class must be one of ("economy", "premium economy", "business", "first")
////      if (!seatingClass.equals("economy") && !seatingClass.equals("economy") && !seatingClass.equals("economy") && !seatingClass.equals("economy"))
//      Set<String> validSeatingClasses = Set.of("economy", "premium economy", "business", "first");
//      if (!validSeatingClasses.contains(seatingClass)) return false;
//
//
//
////      Condition 11. Only the following airports are available: "syd" (Sydney), "mel"
////      (Melbourne), "lax" (Los Angeles), "cdg" (Paris), "del" (Delhi), "pvg" (Shanghai) and
////      "doh" (Doha). eg for a flight from Melbourne to Shanghai, the departure airport code
////      would be "mel" and the destination airport code would be "pvg".
//
//      Set<String> validAirportCodes = Set.of("syd", "mel", "lax", "cdg", "del", "doh");
//      if (!validAirportCodes.contains(departureAirportCode) || !validAirportCodes.contains(destinationAirportCode)) return false;
//
////      Furthermore, the departure airport and destination airport cannot be the same
//      if (departureAirportCode.equals(destinationAirportCode)) return false;
//
//
//      return true;
//   }
//}




package flight;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.ResolverStyle;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class FlightSearch {
   private String  departureDate;
   private String  departureAirportCode;
   private boolean emergencyRowSeating;
   private String  returnDate;
   private String  destinationAirportCode;
   private String  seatingClass;
   private int     adultPassengerCount;
   private int     childPassengerCount;
   private int     infantPassengerCount;

   public boolean runFlightSearch(String departureDate,
                                  String departureAirportCode,
                                  boolean emergencyRowSeating,
                                  String returnDate,
                                  String destinationAirportCode,
                                  String seatingClass,
                                  int adultPassengerCount,
                                  int childPassengerCount,
                                  int infantPassengerCount) {

      boolean valid = true;

      //TODO: Validate all the provided parameters.
      //if the search parameters meets the given conditions,
      //   the function should initialise all the class attributes and return true.
      //else
      //   the function should return false

      // Condition 1. The total number of passenger per search must be at least 1 and cannot exceed 9.
      int totalPassengers = adultPassengerCount + childPassengerCount + infantPassengerCount;
      if (totalPassengers < 1 || totalPassengers > 9) return false;

      // Condition 2. Children cannot be seated in emergency row seating or first class.
      if (childPassengerCount > 0) {
         if (emergencyRowSeating) return false;
         if (seatingClass.equals("first")) return false;
      }

      // Condition 3. Infants cannot be seated in emergency row seating or business class.
      if (infantPassengerCount > 0) {
         if (emergencyRowSeating) return false;
         if (seatingClass.equals("first")) return false;
      }

      // Condition 4. All children (aged 2-11 years old) must be seated immediately next to at least one adult passenger (ie up to 2 children per adult).
      // eg if the adult passenger count is 2, then up to 4 child passengers are allowed.
      if (childPassengerCount > adultPassengerCount * 2) return false;
      if (childPassengerCount > 0 && adultPassengerCount == 0) return false;

      // Condition 5. Each infant (<2 years old) must be seated on an accompanying adults lap (only one infant is allowed per adult)
      if (infantPassengerCount > adultPassengerCount) return false;
      if (infantPassengerCount > 0 && adultPassengerCount == 0) return false;

      // Condition 6. The departure date cannot be in the past (this is based on the current date when runFlightSearch method is called).
      if (departureDate == null || returnDate == null) return false;

//      if (!isValidDate(departureDate)) return false;
//      if (!isValidDate(returnDate)) return false;

//      Condition 7. All dates must be formatted in the format DD/MM/YYYY
      DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/uuuu").withResolverStyle(ResolverStyle.STRICT);
      LocalDate localDepartureDate;
      LocalDate localReturnDate;
      try {
         localDepartureDate = LocalDate.parse(departureDate, formatter);
         localReturnDate = LocalDate.parse(returnDate, formatter);
      } catch (Exception e) {
         System.err.println("Error parsing date:" + e.toString());
         return false;
      }

      LocalDate today = LocalDate.now();

      if (localDepartureDate.isBefore(today)) return false;
//      str1 == str2 => str1.equals(str2)

//      Condition 8: return date cannot be before departure date
      if (localReturnDate.isBefore(localDepartureDate)) return false;


      // Condition 9. The seating class must be one of ("economy', "premium economy", "business", "first").
      Set<String> validClasses = Set.of("economy", "premium economy", "business", "first");
      if (seatingClass == null || !validClasses.contains(seatingClass)) return false;

      // Condition 10. Only economy class flights have emergency row seating.
      if (emergencyRowSeating && !"economy".equals(seatingClass)) return false;

      /// Condition 11. Only the following airports are available: "syd" (Sydney), "mel" (Melbourne), "lax" (Los Angeles), "cdg" (Paris), "del" (Delhi), "pvg" (Shanghai) and "doh" (Doha).
      // eg for a flight from Melbourne to Shanghai, the departure airport code would be "mel" and the destination airport code would be "pvg".
      // Furthermore, the departure airport and destination airport cannot be the same.
      Set<String> validAirports = Set.of("syd", "mel", "lax", "cdg", "del", "doh");
      if (departureAirportCode == null || destinationAirportCode == null) return false;
      if (!validAirports.contains(departureAirportCode) || !validAirports.contains(destinationAirportCode)) return false;
      if (departureAirportCode.equals(destinationAirportCode)) return false;




      return valid;
   }

   boolean isValidDate(String dateStr) {
      String[] parts = dateStr.split("/");

      if (parts.length != 3) return false;

      String date = parts[0];
      String month = parts[1];
      String year = parts[2];

      if (date.length() != 2) return false;
      if (month.length() != 2) return false;
      if (year.length() != 4) return false;

//      boolean isLeapYear = false;
//
//      try
//         int(date), int month, int year
//     except: error
//
//      if date: int < 1 or date > 31
//
//
//     if feb:
//         if isLeapYear:
//            if date < 1 or date > 29: return false
//        else:
//         if date < 1 or date > 28: return false
//      check for leap year:
//      2028 -> 29/2

      System.out.println("date is invalid: " + date);

      return true;
   }
}