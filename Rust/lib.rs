use std::io;

macro_rules! parse_input {
    ($x:expr, $t:ident) => ($x.trim().parse::<$t>().unwrap())
}

fn input() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line.trim().to_string()
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
fn main() {
    let l = parse_input!(input(), i32);
    let h = parse_input!(input(), i32);
    let text = input().trim_matches('\n').to_string();
    for i in 0..h as usize {
        let row = input().trim_matches('\n').to_string();
    }

    // Write an answer using println!("message...");
    // To debug: eprintln!("Debug message...");

    println!("answer");
}


