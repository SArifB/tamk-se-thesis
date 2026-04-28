import { useState } from 'react'
import './App.css'

import createModule from "cpp-lib2";
const cpp_lib2 = await createModule();

function App() {
  const [count, setCount] = useState(0n)

  return (
    <>
      <section id="center">
        <button
          type="button"
          className="counter"
          onClick={() => setCount((count) => cpp_lib2.add(count, 1n))}
        >
          Count is {count}
        </button>
      </section>
    </>
  )
}

export default App
