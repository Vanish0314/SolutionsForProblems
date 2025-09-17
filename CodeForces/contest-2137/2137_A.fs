open System

let solve k x = x <<< (k-1)

let readInts () =
    let mutable line = Console.ReadLine()
    while (line <> null && line.Trim().Length = 0) do
        line <- Console.ReadLine()
    if isNull line then [||]
    else line.Split([| ' '; '\t' |], StringSplitOptions.RemoveEmptyEntries) |> Array.map int

[<EntryPoint>]
let main _argv =
    printfn "Hello, F#!"

    let t = Console.ReadLine() |> int
    for _ in 1 .. t do
        let arr = readInts()
        let k = arr.[0]
        let x = arr.[1]
        solve k x |> printfn "%d"
    0


