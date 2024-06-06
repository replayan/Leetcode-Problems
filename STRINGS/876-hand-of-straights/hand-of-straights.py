class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        # Check if the total number of cards is divisible by groupSize
        if len(hand) % groupSize != 0:
            return False

        # Count the frequency of each card
        card_count = Counter(hand)

        # Iterate over the cards in sorted order
        for card in sorted(card_count):
            if card_count[card] > 0:  # If there are any of this card left to place in groups
                count = card_count[card]
                for i in range(groupSize):
                    if card_count[card + i] < count:
                        return False
                    card_count[card + i] -= count

        return True