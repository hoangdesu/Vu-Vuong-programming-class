import { EntitySchema } from 'typeorm';

export default new EntitySchema({
  name: 'Game', // default table name: 'game'
  tableName: 'myGames',
  columns: {
    id: {
      primary: true,
      type: 'int',
      generated: true,
    },
    name: {
      type: 'varchar',
    },
    rating: {
      type: 'float',
    },
  },
});
