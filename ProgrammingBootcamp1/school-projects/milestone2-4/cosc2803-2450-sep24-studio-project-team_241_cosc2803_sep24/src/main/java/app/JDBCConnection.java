package app;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

/**
 * Class for Managing the JDBC Connection to a SQLLite Database.
 * Allows SQL queries to be used with the SQLLite Databse in Java.
 *
 * @author Timothy Wiley, 2023. email: timothy.wiley@rmit.edu.au
 * @author Santha Sumanasekara, 2021. email: santha.sumanasekara@rmit.edu.au
 * @author Halil Ali, 2024. email: halil.ali@rmit.edu.au
 */

public class JDBCConnection {

  // Name of database file (contained in database folder)
  public static final String DATABASE =
    "jdbc:sqlite:database/WasteRecycling.db";

  /**
   * This creates a JDBC Object so we can keep talking to the database
   */
  public JDBCConnection() {
    System.out.println("Created JDBC Connection Object");
  }

  public Connection connect() {
    Connection conn = null;
    try {
      conn = DriverManager.getConnection(DATABASE);
      // System.out.println("Connection to SQLite has been established.");
    } catch (SQLException e) {
      System.out.println(e.getMessage());
    }
    return conn;
  }

  /**
   * Get all of the Countries in the database.
   * @return
   *    Returns an ArrayList of LGA objects
   */
  public ArrayList<LGA> getAllCountries() {
    // Create the ArrayList of LGA objects to return
    ArrayList<LGA> lgas = new ArrayList<LGA>();

    // Setup the variable for the JDBC connection
    Connection connection = null;

    try {
      // Connect to JDBC data base
      connection = DriverManager.getConnection(DATABASE);

      // Prepare a new SQL Query & Set a timeout
      Statement statement = connection.createStatement();
      statement.setQueryTimeout(30);

      // The Query
      String query = "SELECT * FROM lga";

      // Get Result
      ResultSet results = statement.executeQuery(query);

      // Process all of the results
      while (results.next()) {
        // Lookup the columns we need
        int code = results.getInt("code");
        String name = results.getString("name");

        // Create an LGA Object
        LGA lga = new LGA(code, name);

        // Add the LGA object to the array
        lgas.add(lga);
      }

      // Close the statement because we are done with it
      statement.close();
    } catch (SQLException e) {
      // If there is an error, lets just pring the error
      System.err.println(e.getMessage());
    } finally {
      // Safety code to cleanup
      try {
        if (connection != null) {
          connection.close();
        }
      } catch (SQLException e) {
        // connection close failed.
        System.err.println(e.getMessage());
      }
    }

    // Finally we return all of the countries
    return lgas;
  }

  // TODO: Add your required methods here

  public ArrayList<LGA> getAllLgasByRegionType() {
    ArrayList<LGA> lgas = new ArrayList<>();

    String query =
      """
      SELECT Lga.code, Lga.name, RegionType.name AS RegionType FROM Lga
        JOIN RegionType
        ON Lga.regionType = RegionType.regionType
        ;
        """;

    try (
      Connection conn = this.connect();
      PreparedStatement pstmt = conn.prepareStatement(query)
    ) {
      try (ResultSet rs = pstmt.executeQuery()) {
        while (rs.next()) {
          int code = rs.getInt("code");
          String name = rs.getString("name");
          String regionType = rs.getString("RegionType");

          LGA lga = new LGA(code, name, regionType);
          System.out.println("Adding LGA: " + lga.toString());

          lgas.add(lga);
        }
      }
    } catch (SQLException e) {
      System.out.println(e.getMessage());
    }

    return lgas;
  }
}
