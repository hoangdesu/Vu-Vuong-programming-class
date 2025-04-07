// console.log('hello from file focused view');

// const btnToggleTable = document.querySelector('#btn-toggle-table');
// const dataTable = document.querySelector('#data-table');

// let showTable = false;
// dataTable.style.display = 'none';

// btnToggleTable.addEventListener('click', () => {
//     if (showTable) {
//         dataTable.style.display = 'none';
//     } else {
//         dataTable.style.display = 'block';
//     }

//     showTable = !showTable;
// });

const thresholdSlider = document.querySelector("#threshold-slider");
const thresholdLabel = document.querySelector("#threshold-label");

thresholdSlider.addEventListener("input", (e) => {
  const sliderValue = e.target.value;
  console.log(sliderValue);
  let nf = new Intl.NumberFormat("en-US");
  thresholdLabel.textContent = `Threshold (${nf.format(sliderValue)}/100,000)`;
});
