open Game;

let suiteToString = (suite: suite) =>
  switch (suite) {
  | Clubs => "Clubs"
  | Diamonds => "Diamonds"
  | Hearts => "Hearts"
  | Spades => "Spades"
  };

let rankToString = (rank: rank) =>
  switch (rank) {
  | King => "King"
  | Queen => "Queen"
  | Jack => "Jack"
  | Number(x) => string_of_int(x)
  | Ace => "Ace"
  };

let cardToString = (card: card) => {
  let (suite, rank) = card;
  rankToString(rank) ++ " of " ++ suiteToString(suite);
};

let component = ReasonReact.statelessComponent("App");

let make = (~card: card, _children) => {
  ...component,
  render: _self => <p> {ReasonReact.string(cardToString(card))} </p>,
};
