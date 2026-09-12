import "reflect-metadata";
import express from "express";
import { AppDataSource } from "./data-source";
import userRoutes from "./routes/user.routes";
import cors from "cors";
const app = express();
const PORT = process.env.PORT || 3001;

app.use(cors());
app.use(express.json());
app.use("/api", userRoutes);

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



// Client (React)

// Server (Express + NodeJS)

// [TypeORM]

// DB (MS SQL)





// Client (React)

// Server (Express + NodeJS) [Raw SQL]

// DB (MS SQL)