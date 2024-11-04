package app;

import java.util.ArrayList;

import io.javalin.http.Context;
import io.javalin.http.Handler;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

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
        ".carousel { display: flex; justify-content: center; align-items: center; width: 60%; margin: 20px 0; }" +
        ".carousel img { width: 100%; height: auto; }" +
        ".carousel button { background-color: #333; color: #f4f4f4; border: none; padding: 10px; cursor: pointer; }" +
        ".btn-group { margin-top: 20px; }" +
        ".btn-group button { margin: 5px; padding: 10px 20px; background-color: #333; color: #f4f4f4; border: none; cursor: pointer; }" +
        ".btn-group button:hover { background-color: #575757; }" +
        ".graphs { display: flex; justify-content: space-around; width: 80%; margin: 20px 0; }" +
        ".graph-item { width: 30%; text-align: center; background-color: #ddd; padding: 10px; border-radius: 8px; }" +
        ".footer { background-color: #333; color: #f4f4f4; text-align: center; padding: 10px; position: fixed; bottom: 0; width: 100%; }" +
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
        // <a herf = "/" id="navbar__logo">logo.png</a>
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
        //ArrayList<String> lgas = getAllLGAs();


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



        html += """
            <div class='btn-group'>
                <button>LGA's (2018-2019)</button>
                <button>LGA's (2019-2020)</button>
                <button>House Surveyed (2018-2019)</button>
                <button>House Surveyed (2019-2020)</button>
            </div>
        """;

        

        // Graph section
        html += """
            <div class='graphs'>
                <div class='graph-item'>Graph 1</div>
                <div class='graph-item'>Graph 2</div>
                <div class='graph-item'>Graph 3</div>
            </div>
        """;

        // Add HTML for the LGA list
        html += "<h1>All LGAs (from 2018-2019) in the Waste Recycling database</h1><ul>";

        // // Finally, we can print out all of the LGAs
        // for (String name : lgas) {
        //     html += "<li>" + name + "</li>";
        // }

        // Finish the List HTML
        html += "</ul>";

        // Close Content div
        html += "</div>";

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

    /**
     * Get the names of the LGAs in the database.
     */
    // public ArrayList<String> getAllLGAs() {
    //     // Create the ArrayList of String objects to return
    //     ArrayList<String> lgas = new ArrayList<>();

    //     // Setup the variable for the JDBC connection
    //     Connection connection = null;

    //     try {
    //         // Connect to JDBC database
    //         connection = DriverManager.getConnection(JDBCConnection.DATABASE);

    //         // Prepare a new SQL Query & Set a timeout
    //         Statement statement = connection.createStatement();
    //         statement.setQueryTimeout(30);

    //         // The Query
    //         String query = "SELECT name FROM lga";

    //         // Get Result
    //         ResultSet results = statement.executeQuery(query);

    //         // Process all of the results
    //         while (results.next()) {
    //             String lgaName = results.getString("name");

    //             // Add the LGA name to the array
    //             lgas.add(lgaName);
    //         }

    //         // Close the statement
    //         statement.close();
    //     } catch (SQLException e) {
    //         // If there is an error, print the error
    //         System.err.println(e.getMessage());
    //     } finally {
    //         // Safety code to cleanup
    //         try {
    //             if (connection != null) {
    //                 connection.close();
    //             }
    //         } catch (SQLException e) {
    //             // Connection close failed.
    //             System.err.println(e.getMessage());
    //         }
    //     }

    //     // Return all of the LGAs
    //     return lgas;
    // }
}
