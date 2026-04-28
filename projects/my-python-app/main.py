from rust_lib1._core import add as rust_add


def main():
  print("Hello from my-python-app!")
  print(f"rust_add(2, 2) = {rust_add(2, 2)}")


if __name__ == "__main__":
  main()
