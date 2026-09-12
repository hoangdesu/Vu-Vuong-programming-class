import { Router } from "express";
import { TutorialController } from "../controller/TutorialController";

const router = Router(); // creates an instance of the Express router
const tutorialController = new TutorialController();

router.get("/tutorials", async (req, res) => {
  if (req.query.title) {
    await tutorialController.findByTitle(req, res);
  } else {
    await tutorialController.all(req, res);
  }
});

router.get("/tutorials/:id", async (req, res) => {
  await tutorialController.one(req, res);
});

router.post("/tutorials", async (req, res) => {
  await tutorialController.save(req, res);
});

router.put("/tutorials/:id", async (req, res) => {
  await tutorialController.update(req, res);
});

router.delete("/tutorials/:id", async (req, res) => {
  await tutorialController.remove(req, res);
});

router.delete("/tutorials-delete", async (req, res) => {
  await tutorialController.removeAll(req, res);
});

export default router;
