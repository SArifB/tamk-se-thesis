import os
from typing import Annotated

from fastapi import Header, HTTPException

TOKEN_HEADER_VALUE = os.getenv("TOKEN_HEADER_VALUE")
if TOKEN_HEADER_VALUE is None:
  raise RuntimeError("TOKEN_HEADER_VALUE environment variable is not set")
TOKEN_QUERY_VALUE = os.getenv("TOKEN_QUERY_VALUE")
if TOKEN_QUERY_VALUE is None:
  raise RuntimeError("TOKEN_QUERY_VALUE environment variable is not set")


async def get_token_header(x_token: Annotated[str, Header()]):
  if x_token != TOKEN_HEADER_VALUE:
    raise HTTPException(status_code=400, detail="X-Token header invalid")


async def get_query_token(token: str):
  if token != TOKEN_QUERY_VALUE:
    raise HTTPException(status_code=400, detail="Query token invalid")
