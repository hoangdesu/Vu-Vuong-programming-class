import "reflect-metadata";
import { DataSource } from "typeorm";
import { Tutorial } from "./entity/Tutorial";
import { Comment } from "./entity/Comment";

export const AppDataSource = new DataSource({
  type: "mssql",
  host: "dipto-database.cn2ems8y2mfe.ap-southeast-2.rds.amazonaws.com",
  username: "diptoStudent",
  password: "COSC2758-2026@!",
  database: "diptoStudent",
      options: {
        encrypt: false, // Use this for Azure SQL Database
        //trustedConnection: false // Use this for Windows Authentication (if applicable)
    },
  // synchronize: true will automatically create database tables based on entity definitions
  // and update them when entity definitions change. This is useful during development
  // but should be disabled in production to prevent accidental data loss.
  synchronize: true, 
  logging: true, // Enable logging for debugging purposes
  entities: [Tutorial, Comment], // Register the Tutorial entity with TypeORM, allowing it to manage the corresponding database table and perform CRUD operations based on the defined schema.
  migrations: [],
  subscribers: [],
});