// 'use client';

import React from 'react';

// params: inputs for a function
// props: inputs for a component

const VideoComponent = (props) => {
  const { title, views } = props;

  return (
    <div>
      <h1>{title}</h1>
      <p>{views} views</p>
    </div>
  );
};

export default VideoComponent;
