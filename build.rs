fn main() {
    // Assume we're using homebrew 🍎
    println!("cargo::rustc-link-search=native=/opt/homebrew/lib");
    for name in ["system", "audio", "graphics", "window", "network"] {
        println!("cargo:rustc-link-lib=dylib=csfml-{name}");
        // Doesn't seem to be necessary
        //println!("cargo:rustc-link-lib=dylib=sfml-{name}");
    }
}
