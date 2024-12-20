package app;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

import io.javalin.http.Context;
import io.javalin.http.Handler;

/**
 * Example Index HTML class using Javalin
 * <p>
 * Generate a static HTML page using Javalin
 * by writing the raw HTML into a Java String object
 *
 * @author Timothy Wiley, 2023. email: timothy.wiley@rmit.edu.au
 * @author Santha Sumanasekara, 2021. email: santha.sumanasekara@rmit.edu.au
 * @author Halil Ali, 2024. email: halil.ali@rmit.edu.au
 */

public class PageIndex implements Handler {

    // URL of this page relative to http://localhost:7001/
    public static final String URL = "/";

    @Override
    public void handle(Context context) throws Exception {
        // Create a simple HTML webpage in a String
        String html = "<html>";

        // Add some Header information
        html += "<head>" + 
                "<title>Landing Page</title>";

            // Add some Header information
            html += "<head>" +
            "<title>Landing Page</title>" +
            "<style>" +
            "body { font-family: Arial, sans-serif; background-color: #f4f4f4; margin: 0; padding: 0; }" +
            ".topnav { background-color: #333; overflow: hidden; padding: 10px; }" +
            ".topnav a { color: #f4f4f4; text-decoration: none; padding: 14px 20px; display: inline-block; }" +
            ".topnav a:hover { background-color: #575757; }" +
            ".header { text-align: center; padding: 20px; }" +
            ".header img { vertical-align: middle; }" +
            ".content { display: flex; flex-direction: column; align-items: center; padding: 20px; }" +
            ".carousel-container { display: flex; justify-content: center; align-items: center; width: 60%; margin: 20px 0; }" +
            ".carousel img { width: 100%; height: auto; }" +
            ".carousel-button { background-color: #333; color: #f4f4f4; border: none; padding: 10px; cursor: pointer; }" +
            ".database-section { margin-top: 40px; width: 80%; text-align: center; }" +
            ".database-title { font-size: 28px; font-weight: bold; color: #333; margin-bottom: 10px; }" +
            ".database-subtitle { font-size: 18px; color: #666; margin-bottom: 20px; }" +
            ".database-table { border-collapse: collapse; width: 100%; margin-top: 20px; }" +
            ".database-table th, .database-table td { border: 1px solid #ddd; padding: 16px; text-align: center; }" +
            ".database-table th { background-color: #4CAF50; color: white; font-size: 18px; }" +
            ".database-table td { background-color: #f9f9f9; font-size: 16px; }" +
            ".database-table tr:nth-child(even) { background-color: #f2f2f2; }" +
            ".footer { background-color: #333; color: #f4f4f4; text-align: center; padding: 7px; bottom: 0; width: 100%; }" +
            ".footer button { background-color: #555; color: #f4f4f4; padding: 5px 10px; border: none; cursor: pointer; margin: 0 5px; }" +
            ".footer button:hover { background-color: #777; }" +
            "</style>" +
            "</head>";


        // Add some CSS (external file)
        html += "<link rel='stylesheet' type='text/css' href='common.css' />";
        html += "</head>";

        // Add the body
        html += "<body>";

        // Add the topnav
        html += """
            <div class='topnav'>
                <a href='/'>Homepage</a>
                <a href='mission.html'>Our Mission</a>
                <a href='page2A.html'>LGA (2019-2020)</a>
                <a href='page2B.html'>Focused View</a>
                <a href='page3A.html'>Similar LGAs</a>
                <a href='page3B.html'>Identify Changes</a>
            </div>
        """;

        // Add header content block
       
         html += """
            <div class='header'>
                <h1>
                    <img src='logo.png' class='top-image' alt='RMIT logo' height='75'>
                    Homepage
                </h1>
            </div>
        """;

        // Add Div for page Content
        html += "<div class='content'>";

        // Add HTML for the page content
        html += "<p>Landing Page</p>";

        // Get the ArrayList of Strings of all LGAs

        html += """
            <div class='carousel'>
                <button onclick='prevSlide()'>&lt;</button>
                <img id='carousel-image' src='zero wast1.png' alt='Zero Waste Image'>
                <button onclick='nextSlide()'>&gt;</button>
            </div>
        
            <script>
                // JavaScript code to make the carousel functional
                const images = ['zero wast1.png', 'zero-waste2.png', 'images.png'];
                let currentIndex = 0;
        
                function showSlide(index) {
                    const imageElement = document.getElementById('carousel-image');
                    imageElement.src = images[index];
                }
        
                function nextSlide() {
                    currentIndex = (currentIndex + 1) % images.length;
                    showSlide(currentIndex);
                }
        
                function prevSlide() {
                    currentIndex = (currentIndex - 1 + images.length) % images.length;
                    showSlide(currentIndex);
                }
            </script>
        """;

html += """
     <style>
         .carousel {
             display: flex;
             align-items: center;
             justify-content: center;
             margin-top: 20px;
         }
         .carousel img {
             max-width: 300px;
             height: auto;
             border-radius: 8px;
             margin: 0 10px;
         }
         .carousel button {
             background-color: #333;
         color: #f4f4f4;
             border: none;
             padding: 10px;
             cursor: pointer;
             font-size: 20px;
         }
     </style>
""";

             // Placeholder for database data
             ArrayList<String> A1t = table();
        
        html += "<div class=\"text-center\">";
        html += "<h3 class=\"index-head text-info mt-2\">Yearly Data</h3>";
        html += "<div class=\"d-flex flex-row justify-content-center\">";
        html += "<table>";
        html += "<tr>";
        html += "<table class=\"database-table\">\r\n" + //
                        "            <tr>\r\n" + //
                        "                <th>Year</th>\r\n" + //
                        "                <th>LGAs (Local Government Areas)</th>\r\n" + //
                        "                <th>Houses Surveyed</th>\r\n" + //
                        "            </tr>";
            html += "<tr>";
            html += "<td class=\"text-center\">2018-2019</td>";
            html += "<td class=\"text-center p-1\">" + A1t.get(0) + "</td>";
            html += "<td class=\"text-center p-1\">" + A1t.get(1) + "</td>";
            html += "</tr>";
            ArrayList<String> A2t = table2();
            html += "<tr>";
            html += "<td class=\"text-center\">2019-2020</td>";
            html += "<td class=\"text-center p-1\">" + A2t.get(0) + "</td>";
            html += "<td class=\"text-center p-1\">" + A2t.get(1) + "</td>";
            html += "</tr>";
        

        html += "</table>";
        html += "</div>";
        html += "</div>";
        
        // Finish the List HTML
        html += "</ul>";

       
        // Footer
          
         
         // About Us and Contact Us buttons
         html += """
        <div class='footer'>
            <button>FOLLOW US</button>
            <button>ABOUT US</button>
            <button>CONTACT US</button>
        </div>
    """;
        
           
        
        // Finish the HTML webpage
        html += "</body></html>";

        // Makes Javalin render the webpage
        context.html(html);

        }
        public ArrayList<String> table() {
            ArrayList<String> tresults = new ArrayList<>();
            Connection connection = null;
            try {
                connection = DriverManager.getConnection(JDBCConnection.DATABASE);
                Statement statement = connection.createStatement();
                statement.setQueryTimeout(30);
    
                String query = "SELECT  COUNT(LGANAME) AS TOTAL, \r\n" + //
                                        "SUM(HouseholdsSurveyed) AS TotalHouseholdsSurveyed FROM LGA_Services18_19";
                                        
    
                ResultSet results = statement.executeQuery(query);
    
                if (!results.next()) {
                    System.out.println("No data available.");
                } else {
                    do {
                         String L18 = results.getString("Total");
                         tresults.add(L18);
                         String H18 = results.getString("TotalHouseholdsSurveyed");
                        tresults.add(H18);
                        
                    } while (results.next());
                }
    
                statement.close();
            } catch (SQLException e) {
                System.err.println(e.getMessage());
            } finally {
                try {
                    if (connection != null) {
                        connection.close();
                    }
                } catch (SQLException e) {
                    System.err.println(e.getMessage());
                }
            }
            return tresults;
        }

        public ArrayList<String> table2() {
            ArrayList<String> tresults = new ArrayList<>();
            Connection connection = null;
            try {
                connection = DriverManager.getConnection(JDBCConnection.DATABASE);
                Statement statement = connection.createStatement();
                statement.setQueryTimeout(30);
    
                String query = "SELECT COUNT(LGANAME) AS TOTAL2, SUM(HouseholdsSurveyed) AS TotalHouseholdsSurveyed2 FROM LGA_Services19_20";
                                        
    
                ResultSet results = statement.executeQuery(query);
    
                if (!results.next()) {
                    System.out.println("No data available.");
                } else {
                    do {
                         String L18 = results.getString("TOTAL2");
                         tresults.add(L18);
                         String H18 = results.getString("TotalHouseholdsSurveyed2");
                        tresults.add(H18);
                    } while (results.next());
                }
    
                statement.close();
            } catch (SQLException e) {
                System.err.println(e.getMessage());
            } finally {
                try {
                    if (connection != null) {
                        connection.close();
                    }
                } catch (SQLException e) {
                    System.err.println(e.getMessage());
                }
            }
            return tresults;
        }

      
}
