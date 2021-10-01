const arr = [1, 3, 5, 7, 9]


let minorValue = 0
let maxValue = 0
let minSum = 0
let maxSum = 0
let minQtd = 0
let maxQtd = 0
arr.map((item, index) => {
    if(index == 0){
        minorValue = item
        maxValue = item
    }
    if(item < minorValue) minorValue = item
    
    if(item > maxValue) maxValue = item

})
arr.map(item => {
    if(item === minorValue) minQtd = minQtd + 1
    if(item === maxValue) maxQtd = maxQtd + 1
    
})    

arr.map((item, index) => {
    if(item === minorValue && minQtd > 1){
        maxSum += minorValue
        minQtd --
    }
    if(item === maxValue && maxQtd > 1){
        minSum += maxValue
        maxQtd --
    }
    if(item !== minorValue) maxSum = maxSum + item
    if(item !== maxValue) minSum = minSum + item
})
console.log(minSum, maxSum)

