import './App.css'

import { MyPyMessage } from 'js-lib1'
import { useState } from 'react'

function App() {
  const [count, setCount] = useState(0)

  return (
    <>
      <section id="center">
        <button
          className="counter"
          onClick={() => setCount((count) => count + 1)}
        >
          Count is {count}
        </button>

        <MyPyMessage />

      </section>

      <section id="spacer"></section>
    </>
  )
}

export default App
