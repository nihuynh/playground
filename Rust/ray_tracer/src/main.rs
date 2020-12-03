use std::fs::File;
use std::io::prelude::*;

const WIDTH: i32 = 256;
const HEIGHT: i32 = 256;

fn output_ppm() -> std::io::Result<()> {
	let mut file = File::create("foo.ppm")?;
	write!(file, "P3\n{} {}\n255\n", WIDTH, HEIGHT)?;
	for y in (0..HEIGHT).rev() {
		eprintln!(
			"Current line {:<3} [{:1.2} %]",
			y,
			100_f32 - y as f32 / (HEIGHT - 1) as f32 * 100_f32
		);
		for x in 0..WIDTH {
			let (r, g, b) = (x as f32 / (WIDTH - 1) as f32, y as f32 / (HEIGHT - 1) as f32, 0.25);
			let ir: i32 = (255.999 * r) as i32;
			let ig: i32 = (255.999 * g) as i32;
			let ib: i32 = (255.999 * b) as i32;
			write!(file, "{} {} {}\n", ir, ig, ib)?;
		}
	}
	Ok(())
}

fn main() {
	match output_ppm() {
		Ok(()) => println!("All good, here is your cat pic."),
		Err(e) => println!("error creating the image: {:?}", e),
	}
}
