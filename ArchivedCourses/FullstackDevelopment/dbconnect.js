const sql = require('mssql'); // Import the mssql package

// Note: Ensure you have the mssql package installed in your project by running:
// npm install mssql
// or to create a package.json file, run:
// npm install mssql --save
// This code connects to a SQL Server database using the mssql package and queries the Person table.

/* Database schema for the Person table:
CREATE TABLE [dbo].[Person](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[Name] [varchar](50) NULL,
	[Age] [int] NULL,
 CONSTRAINT [PK_NewTable] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
))*/

/*
Populate the Person table with some sample data:
INSERT INTO [dbo].[Person] (Name, Age) VALUES ('Alice', 30);
INSERT INTO [dbo].[Person] (Name, Age) VALUES ('Bob', 25);
INSERT INTO [dbo].[Person] (Name, Age) VALUES ('Charlie', 35);
*/

// Make sure to replace the configuration details with your actual database credentials and server information.
// to run: node dbconnect.js

// Configuration details for your database
const config = {
    user: 'diptoStudent', // Your database username, replace it with your RMIT student email username (without the @rmit.edu.au part)
    password: 'COSC2758-2026@!', // Your database password, you will need to set this up in your database server, 
    // you will be prompted to create a password when you set up your database server, make sure to use the same password here
    server: 'dipto-database.cn2ems8y2mfe.ap-southeast-2.rds.amazonaws.com', // Your database server address
    database: 'diptoStudent', // Your database name
    options: {
        encrypt: false, // Use this if you're on Windows Azure - for local development, set to false
        trustedConnection: false // Set to true if you're using Windows Authentication - for SQL Server, set to false for SQL Authentication
    }
};

async function connectAndQuery() {
    try {
        // Connect to the database
        await sql.connect(config);
        console.log("Connected to the database successfully!");

        // Query the database
        const result = await sql.query`SELECT * FROM Person`;
        console.log(result.recordset);

    } catch (err) {
        console.error('Database connection failed: ', err);
    } finally {
        // Close the connection when the application is finished
        await sql.close();
        console.log("Connection closed.");
    }
}

connectAndQuery(); // Call the function to connect and query the database