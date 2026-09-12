import {
  Entity,
  PrimaryGeneratedColumn,
  Column,
  CreateDateColumn,
  ManyToOne,
} from "typeorm";
import { Tutorial } from "./Tutorial";

@Entity()
export class Comment {
  @PrimaryGeneratedColumn()
  id: number;

  @Column()
  content: string;

  @Column()
  author: string;

  @CreateDateColumn()
  createdAt: Date;

  @ManyToOne(() => Tutorial, (tutorial) => tutorial.comments, {
  lazy: true, // Enable lazy loading for the tutorial relationship,
  // which means the related tutorial will only be loaded when accessed, 
  // improving performance by avoiding unnecessary data retrieval.
  })
  tutorial: Tutorial;
}
