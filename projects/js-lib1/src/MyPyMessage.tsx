import { useEffect, useState } from 'react'
import z from 'zod'

const pyApiDataSchema = z.object({ message: z.string() })
type PyApiData = z.output<typeof pyApiDataSchema>

async function fetchPyApiData() {
  return fetch("http://127.0.0.1:3000/py_api_data", {
    headers: { accept: "application/json" }
  })
    .then(x => x.json())
    .then(x => pyApiDataSchema.parseAsync(x))
}

export function MyPyMessage() {
  const [data, setData] = useState(undefined as PyApiData | undefined)

  useEffect(() => {
    fetchPyApiData()
      .then(data => setData(data))
  }, [])

  return (
    <p>
      message: {data?.message || "undefined"}
    </p>
  )
}
