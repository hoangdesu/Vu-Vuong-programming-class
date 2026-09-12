import "reflect-metadata"; // necessary for TypeORM to work properly, as it relies on decorators and metadata reflection.
import express from "express"; // the Express framework to create the server and handle routing.
import { AppDataSource } from "./data-source"; // will be used to initialize the database connection.
import tutorialRoutes from "./routes/tutorial.routes"; //will handle API endpoints related to tutorials. This file should export an Express router with defined routes for CRUD operations on tutorials.
import cors from "cors"; // the CORS middleware to enable Cross-Origin Resource Sharing, allowing the server to handle requests from different origins (useful for frontend applications running on a different domain or port).
const app = express(); // creates an instance of the Express application.
const PORT = process.env.PORT || 3001; // sets the port for the server to listen on, using an environment variable if available, or defaulting to 3001.
app.use(cors()); // enables CORS for all routes, allowing the server to accept requests from any origin.
app.use(express.json()); // middleware to parse incoming JSON requests, making the request body available as req.body in route handlers.
app.use("/api", tutorialRoutes); // mounts the tutorial routes at the /api path, meaning all routes defined in tutorialRoutes will be prefixed with /api (e.g., /api/tutorials).

AppDataSource.initialize()
  .then(() => {
    console.log("Data Source has been initialized!");
    app.listen(PORT, () => {
      console.log(`Server is running on port ${PORT}`);
    });
  })
  .catch((error) =>
    console.log("Error during Data Source initialization:", error)
  );
