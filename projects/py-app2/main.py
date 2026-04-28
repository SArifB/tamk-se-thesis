from cpp_lib2 import add as cpp_add
from rust_lib1 import add as rust_add


def main():
  print("Hello from py-app2!")
  print(f"cpp_add(2, 2) = {cpp_add(2, 2)}")
  print(f"rust_add(2, 2) = {rust_add(2, 2)}")


if __name__ == "__main__":
  main()
