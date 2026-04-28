import { useState } from "react";
import "./App.css";

import init, { add } from "rust-lib1";
await init();

function App() {
  const [count, setCount] = useState(0n);

  return (
    <>
      <section id="center">
        <button
          type="button"
          className="counter"
          onClick={() => setCount((count) => add(count, 1n))}
        >
          Count is {count}
        </button>
      </section>
    </>
  );
}

export default App;
