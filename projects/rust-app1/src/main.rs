use thesis::cpp_lib2::add as cpp_add;
use thesis::rust_lib1::add as rust_add;

fn main() {
  println!("Hello, world!");
  println!("rust_add(2, 2) = {}", rust_add(2, 2));
  println!("cpp_add(2, 2) = {}", cpp_add(2, 2));
}
