import { serve } from '@hono/node-server'
import { Hono } from 'hono'
import { env } from 'hono/adapter'
import { cors } from 'hono/cors'
import z from 'zod'

const app = new Hono()

app.use('/*', cors({
  origin: z.string().parse(process.env.JS_APP1_URL),
}))

app.get('/', (c) => {
  return c.json({ message: 'Hello Hono!' })
})

const pyApiDataSchema = z.object({ message: z.string() })

async function fetchPyApiData(token: string) {
  return fetch(`http://127.0.0.1:8000/hello?token=${token}`, {
    headers: { accept: "application/json" }
  })
    .then(x => x.json())
    .then(x => pyApiDataSchema.parseAsync(x))
}

app.get('/py_api_data', async (c) => {
  const { PY_APP_TOKEN } = env<{ PY_APP_TOKEN: string }>(c)
  const data = await fetchPyApiData(PY_APP_TOKEN)
  // do something with data
  return c.json(data) // for now just send for forward
})

serve({
  fetch: app.fetch,
  port: 3000
}, (info) => {
  console.log(`Server is running on http://localhost:${info.port}`)
})
