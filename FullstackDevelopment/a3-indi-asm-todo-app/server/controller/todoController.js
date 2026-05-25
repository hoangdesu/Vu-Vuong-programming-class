import express from 'express';

const getTodoById = (req, res) => {
    const { id } = req.params
    return res.send(id);
};

export { getTodoById };