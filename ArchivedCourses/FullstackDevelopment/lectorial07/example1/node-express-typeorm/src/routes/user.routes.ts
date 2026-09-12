import { Router } from "express";
import { UserController } from "../controller/UserController";

const router = Router();
const userController = new UserController();

router.get("/users", async (req, res) => {
  
  await userController.all(req, res); // => SELECT * FROM users;
});

router.get("/users/:id", async (req, res) => {
  await userController.one(req, res); // SELECT * FROM users WHERE users.id = id;
});

router.post("/users", async (req, res) => {
  await userController.save(req, res);
});

router.put("/users/:id", async (req, res) => {
  await userController.update(req, res);
});

router.delete("/users/:id", async (req, res) => {
  await userController.remove(req, res);
});

export default router;
