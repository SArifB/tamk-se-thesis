import { serve } from '@hono/node-server'
import { Hono } from 'hono'
import { env } from 'hono/adapter'
import { cors } from 'hono/cors'
import z from 'zod'
import dotenv from 'dotenv'
dotenv.config()

const app = new Hono()

app.use('/*', cors({
  origin: z.string().parse(process.env.JS_APP1_URL),
}))

app.get('/', (c) => {
  return c.json({ message: 'Hello Hono!' })
})

const pyApiDataSchema = z.object({ message: z.string() })

async function fetchPyApiData(token: string) {
  const pyAppUrl = z.url().parse(process.env.PY_APP1_URL)
  return fetch(`${pyAppUrl}/hello?token=${token}`, {
    headers: { accept: "application/json" }
  })
    .then(x => x.json())
    .then(x => pyApiDataSchema.parseAsync(x))
}

app.get('/py_api_data', async (c) => {
  const { PY_APP1_TOKEN_QUERY_VALUE } = env<{ PY_APP1_TOKEN_QUERY_VALUE: string }>(c)
  const data = await fetchPyApiData(PY_APP1_TOKEN_QUERY_VALUE)
  // do something with data
  return c.json(data) // for now just send forward
})

serve({
  fetch: app.fetch,
  port: z.coerce.number().parse(process.env.JS_APP2_PORT),
}, (info) => {
  console.log(`Server is running on http://localhost:${info.port}`)
})
