import os
from typing import Annotated

from dotenv import load_dotenv
from fastapi import Header, HTTPException

load_dotenv()

PY_APP1_TOKEN_HEADER_VALUE = os.getenv("PY_APP1_TOKEN_HEADER_VALUE")
if PY_APP1_TOKEN_HEADER_VALUE is None:
  raise RuntimeError("PY_APP1_TOKEN_HEADER_VALUE environment variable is not set")
PY_APP1_TOKEN_QUERY_VALUE = os.getenv("PY_APP1_TOKEN_QUERY_VALUE")
if PY_APP1_TOKEN_QUERY_VALUE is None:
  raise RuntimeError("PY_APP1_TOKEN_QUERY_VALUE environment variable is not set")


async def get_token_header(x_token: Annotated[str, Header()]):
  if x_token != PY_APP1_TOKEN_HEADER_VALUE:
    raise HTTPException(status_code=400, detail="X-Token header invalid")


async def get_query_token(token: str):
  if token != PY_APP1_TOKEN_QUERY_VALUE:
    raise HTTPException(status_code=400, detail="Query token invalid")
