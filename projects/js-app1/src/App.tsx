import './App.css'
import { useState } from 'react'
import { MyPyMessage } from 'js-lib1'

import createModule from "cpp-lib2";
const cpp_lib2 = await createModule();

import init, * as rust_lib1 from "rust-lib1";
await init();

function App() {
  const [cppCount, setCppCount] = useState(0n)
  const [rustCount, setRustCount] = useState(0n)

  return (
    <>
      <section id="center">
        <button
          className="counter"
          onClick={() => setCppCount((count) => cpp_lib2.add(count, 1n))}
        >
          Cpp count is {cppCount}
        </button>

        <button
          className="counter"
          onClick={() => setRustCount((count) => rust_lib1.add(count, 1n))}
        >
          Rust count is {rustCount}
        </button>

        <MyPyMessage />
      </section>
    </>
  )
}

export default App
