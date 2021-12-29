const array = []
const n = 213

for(let c = 0; c < n; c++)
    {array.push(c)}


const total = 5000
const factor = (n / total).toFixed() == 0 ? 1 : (n / total).toFixed()
let newProducts = []

let actual_index = 0
for(let c = 0; c < factor; c++){
    if(c !== factor){
        newProducts = array.slice(actual_index, actual_index + total)
        console.log(newProducts)
        actual_index += total
    } else {
        newProducts = array.slice(actual_index, n - 1)
    }
    console.log(newProducts)
}
