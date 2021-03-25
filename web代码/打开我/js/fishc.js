const sentence = document.querySelector('.sentence')
const h1 = document.querySelector('h1')
const h2 = document.querySelector('h2')

let wordsToArray = (str) => str.split('').map(e => e === ' ' ? ' ' : e)

function insertSpan(elem, letters, startTime) {
    elem.textContent = ''
    let curr = 0
    let delay = 20
    for (let letter of letters) {
        let span = document.createElement('span')
        span.innerHTML = letter
        span.style.animationDelay = (++curr / delay + (startTime || 0)) + 's'
        elem.appendChild(span)
    }
}

insertSpan(h1, wordsToArray(h1.textContent))
insertSpan(h2, wordsToArray(h2.textContent), .5)

document.addEventListener('mousemove', e => {
    let xpos = e.layerX || e.offsetX
    let ypos = e.layerY || e.offsetY

    let ax = -(window.innerWidth / 2 - xpos) / 20
    let ay = (window.innerHeight / 2 - ypos) / 10

    sentence.style.transform = `rotateY(${ax}deg) rotateX(${ay}deg)`
})