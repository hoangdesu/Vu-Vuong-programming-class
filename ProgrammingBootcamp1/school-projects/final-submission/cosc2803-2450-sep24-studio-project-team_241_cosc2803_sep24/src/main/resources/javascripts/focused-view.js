const thresholdSlider = document.querySelector("#threshold-slider");
const thresholdLabel = document.querySelector("#threshold-label");

thresholdSlider.addEventListener("input", (e) => {
  const sliderValue = e.target.value;
  console.log(sliderValue);
  let nf = new Intl.NumberFormat("en-US");
  thresholdLabel.textContent = `Threshold (${nf.format(sliderValue)}/100,000)`;
});