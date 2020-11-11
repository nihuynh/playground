use std::io;

macro_rules! parse_input {
    ($x:expr, $t:ident) => ($x.trim().parse::<$t>().unwrap())
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

fn input() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line.trim().to_string()
}

// A struct with two fields
struct Cage {
    sick: i32,
    healthy: i32,
    alive: i32,
    dead: i32,
}


fn main() {
    let n = parse_input!(input(), i32);
	let y = parse_input!(input(), i32);
	let mut cages = Vec::new();
	for _i in 0..n as usize {
		let cage = input();
		let inputs = cage.split(" ").collect::<Vec<_>>();

		let current = Cage {
			sick: parse_input!(inputs[0], i32),
			healthy: parse_input!(inputs[1], i32),
			alive: parse_input!(inputs[2], i32),
			dead: 0,
		};
		cages.push(current);
    }
    for _i in 0..y as usize {
		let mut alive = 0;
		for x in &mut cages {
			eprintln!("sick {} healthy {} alive {} dead {}", x.sick, x.healthy, x.alive, x.dead);
			x.dead = x.sick;
			x.alive = x.alive - x.sick;
			alive += x.alive;
			if x.sick != 0 {
				x.sick = x.sick * 2;
				x.healthy = x.healthy - x.sick;
				if x.healthy < 0 {
					x.sick += x.healthy;
					x.healthy = 0;
				}
			}
			eprintln!("sick {} healthy {} alive {} dead {}", x.sick, x.healthy, x.alive, x.dead);
		}
        // Write an answer using println!("message...");
        // To debug: eprintln!("Debug message...");

        // if alive == 0 {
        //    println!("{}", 0);
        //    return ;
        // }
        println!("{}", alive);
    }
}