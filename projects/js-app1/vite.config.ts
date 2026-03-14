import { defineConfig } from 'vite'
import react from '@vitejs/plugin-react'
import z from 'zod'
import dotenv from 'dotenv'
dotenv.config()

// https://vite.dev/config/
export default defineConfig({
  plugins: [react()],
  server: {
    port: z.coerce.number().parse(process.env.JS_APP1_PORT)
  }
})
