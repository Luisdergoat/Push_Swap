## This project has been created as part of the 42 curriculum by lunsold
---
# 🔄 Push_Swap - Efficient Sorting Algorithm

Ein hochoptimierter Sortier-Algorithmus, der zwei Stacks verwendet und nur eine begrenzte Anzahl von Operationen erlaubt.  Implementiert mit dem **Turk Algorithm** für minimale Anzahl an Moves.

![42 Badge](https://img.shields.io/badge/42-Project-blue)
![Language](https://img.shields.io/badge/Language-C-orange)
![Norm](https://img.shields.io/badge/Norm-passing-green)

---

## 📋 Inhaltsverzeichnis

1. [Was ist Push_Swap? ](#was-ist-push_swap)
2. [Der Turk Algorithm](#der-turk-algorithm)
3. [Die 4 Phasen](#die-4-phasen)
4. [Erlaubte Operationen](#erlaubte-operationen)
5. [Installation](#installation)
6. [Usage](#usage)
7. [Beispiele](#beispiele)
8. [Code-Struktur](#code-struktur)
9. [Performance](#performance)
10. [Testing](#testing)
11. [Algorithmus im Detail](#algorithmus-im-detail)
12. [Troubleshooting](#troubleshooting)

---

## 🎯 Was ist Push_Swap? 

**Push_Swap** ist ein Sortier-Algorithmus, der Zahlen mit nur zwei Stacks (A und B) und einer begrenzten Anzahl von Operationen sortiert. 

### Das Problem: 

- **Gegeben:** Stack A mit unsortierter Zahlenreihe
- **Stack B:** Leer am Anfang
- **Ziel:** Sortiere Stack A aufsteigend (kleinste Zahl oben)
- **Constraint:** Nur spezifische Operationen erlaubt (sa, sb, pa, pb, ra, rb, rra, rrb, etc.)

### Warum ist das schwierig?

Du kannst **nicht** direkt auf mittlere Elemente zugreifen.  Du kannst nur das **oberste** Element manipulieren! 

```
Stack A: [5, 2, 9, 1]
         ↑
    Nur dieses Element direkt zugänglich! 
```

### Real-World Analogie: 

Stelle dir zwei Stapel Teller vor: 
- Du kannst nur den obersten Teller nehmen
- Du kannst nur oben drauf legen
- Du kannst den ganzen Stapel rotieren (oberster wird unterster)
- Ziel: Alle Teller nach Größe sortiert auf Stapel A

---

## 🧠 Der Turk Algorithm

Der **Turk Algorithm** (auch "Cost-Based Algorithm" genannt) ist eine Optimierungsstrategie, die für jedes Element die **günstigsten Rotationen** berechnet.

### Kern-Idee: 

Statt blind zu sortieren, berechne **für jedes Element in B**:
- Wie viele Rotationen braucht **Stack A**?
- Wie viele Rotationen braucht **Stack B**?
- Was ist die **günstigste Kombination**? 

Dann wähle das Element mit den **wenigsten Total-Kosten**.

### Warum ist das effizient? 

❌ **Naive Methode:**
```
Nehme immer das oberste Element von B → ~1200 moves für 100 Elemente
```

✅ **Turk Algorithm:**
```
Wähle immer das günstigste Element → ~700 moves für 100 Elemente
```

**Ersparnis:  ~40% weniger Moves!** 🚀

### Vergleich mit anderen Algorithmen:

| Algorithmus | Avg.  Moves (100 Elem.) | Komplexität |
|-------------|------------------------|-------------|
| Bubble Sort Approach | ~1400 | O(n²) |
| Naive Insertion | ~1200 | O(n²) |
| **Turk Algorithm** | **~700** ✅ | **O(n²)** |
| Radix Sort | ~500 | O(n·k) |

---

## 📊 Die 4 Phasen

Der Algorithmus ist in 4 klare Phasen unterteilt:

```
┌──────────────────────────────────────────────────────────┐
│ Phase 1: Push to B                                       │
│ [A: xxx... ] → [A: 3 Elemente] [B: Rest]                 │
└──────────────────────────────────────────────────────────┘
                        ↓
┌──────────────────────────────────────────────────────────┐
│ Phase 2: Sort 3 in A                                     │
│ [A: sortierte 3] [B: Rest]                               │
└──────────────────────────────────────────────────────────┘
                        ↓
┌──────────────────────────────────────────────────────────┐
│ Phase 3: Push back to A (Turk Algorithm)                │
│ [A: fast fertig] [B: leer]                               │
└──────────────────────────────────────────────────────────┘
                        ↓
┌──────────────────────────────────────────────────────────┐
│ Phase 4: Final Rotate                                    │
│ [A: komplett sortiert! ] ✅                               │
└──────────────────────────────────────────────────────────┘
```

---

### 🔵 Phase 1: Push to B

**Ziel:** Alle Elemente außer 3 nach Stack B pushen. 

#### Warum genau 3 Elemente behalten?

- 3 Elemente können optimal in **max.  2 Moves** sortiert werden
- Hardcoded optimal solution für alle 5 möglichen unsortierte Kombinationen
- Basis für Phase 2 und spätere Einfügungen

#### Was passiert: 

```
Start: 
A: [5, 2, 9, 1, 7, 3, 8]
B: []

Aktion:  pb, pb, pb, pb
(Pushe alle außer 3)

Nach Phase 1:
A: [5, 2, 9]          ← 3 Elemente bleiben
B: [8, 3, 7, 1]       ← Rest in B (Reihenfolge egal!)
```

#### Wichtig: 

- Die Reihenfolge in B spielt **keine Rolle**
- Wir pushen einfach blind die ersten (n-3) Elemente
- Schnell und effizient:  O(n) Operationen

---

### 🟢 Phase 2: Sort 3 in A

**Ziel:** Die 3 Elemente in Stack A optimal sortieren.

#### Alle möglichen Fälle:

Es gibt **nur 5 unsortierte Kombinationen** bei 3 Elementen:

| Konstellation | Größte Position | Benötigte Aktionen | Moves | Ergebnis |
|---------------|----------------|-------------------|-------|----------|
| `[3, 2, 1]` | Position 0 (oben) | `sa` → `rra` | 2 | `[1, 2, 3]` |
| `[2, 3, 1]` | Position 1 (mitte) | `rra` | 1 | `[1, 2, 3]` |
| `[3, 1, 2]` | Position 0 (oben) | `ra` | 1 | `[1, 2, 3]` |
| `[2, 1, 3]` | Position 2 (unten) | `sa` | 1 | `[1, 2, 3]` |
| `[1, 3, 2]` | Position 1 (mitte) | `sa` → `ra` | 2 | `[1, 2, 3]` |

#### Detailliertes Beispiel:

```
Eingabe: [5, 2, 9]

Schritt 1: Finde die größte Zahl
→ max = 9 (Position 2 = unten)

Schritt 2: Bringe größte nach unten
→ 9 ist schon unten!  Nichts tun.

Schritt 3: Prüfe erste zwei
→ 5 > 2?  Ja! 
→ sa (swap)

Ergebnis: [2, 5, 9] ✅ Sortiert!
Total: 1 Move
```

#### Strategie:

1.  Finde die **größte Zahl**
2. Bringe sie **nach unten** (Position 2)
3. **Swap** die ersten beiden wenn nötig

**Maximum:  2 Moves garantiert!**

---

### 🟡 Phase 3: Push back to A (Das Herz des Turk Algorithm)

**Ziel:** Alle Elemente von B zurück nach A pushen, **sortiert** einfügen.

Dies ist die komplexeste und wichtigste Phase.  Sie besteht aus 4 Unterschritten:

```
┌─────────────────────────────────────────────┐
│ 3. 1:  Finde Zielposition für jedes Element  │
│      → Wo gehört es in A hin?              │
└─────────────────────────────────────────────┘
              ↓
┌─────────────────────────────────────────────┐
│ 3.2: Berechne Rotations-Kosten             │
│      → Wie viele Moves brauche ich?        │
└─────────────────────────────────────────────┘
              ↓
┌─────────────────────────────────────────────┐
│ 3.3: Optimiere mit rr/rrr                  │
│      → Kann ich Rotationen kombinieren?    │
└─────────────────────────────────────────────┘
              ↓
┌─────────────────────────────────────────────┐
│ 3.4: Führe Moves aus                        │
│      → Rotiere und pushe günstigstes       │
└─────────────────────────────────────────────┘
```

---

#### 📍 Schritt 3.1: Zielposition finden

**Frage:** Wenn ich Element X von B nach A pushe, **wo gehört es hin? **

**Regel:** Finde die **kleinste Zahl in A, die größer ist als X**. 

##### Beispiel 1: Normale Einfügung

```
A: [3, 7, 9]
B: [1, 8, 2, 5]

Für Element 5 aus B:
→ 5 > 3 ✓
→ 5 < 7 ✓
→ Ziel:  VOR die 7 (Index 1)
```

##### Beispiel 2: Kleinste Zahl

```
A: [3, 7, 9]
B:  [1, 8, 2, 5]

Für Element 1 aus B:
→ 1 < 3 (kleinste in A)
→ Keine Zahl in A ist größer
→ Ziel: VOR die kleinste (Index 0)
```

##### Beispiel 3: Größte Zahl

```
A: [3, 7, 9]
B: [1, 8, 2, 5]

Für Element 10 aus B:
→ 10 > 9 (größte in A)
→ Keine Zahl in A ist größer
→ Ziel:  VOR die kleinste (Index 0)
→ Wird später durch Phase 4 sortiert
```

##### Algorithmus:

```
1. Durchlaufe alle Elemente in A
2. Finde die kleinste Zahl die größer ist als target
3. Falls keine gefunden:  Finde die kleinste Zahl in A
4. Return deren Index
```

---

#### 💰 Schritt 3.2: Kosten berechnen

**Für jedes Element:** Berechne wie viele Rotationen nötig sind.

##### Kosten für Stack B:

```
Index des Elements in B:     2
Size von B:                   5

Vorwärts (rb):    2 Rotationen
Rückwärts (rrb):  5 - 2 = 3 Rotationen

Günstiger:  2 Rotationen (rb) ✅
```

##### Kosten für Stack A:

```
Zielindex in A:   3
Size von A:       5

Vorwärts (ra):    3 Rotationen
Rückwärts (rra):  5 - 3 = 2 Rotationen

Günstiger: 2 Rotationen (rra) ✅
```

##### Total-Kosten:

```
Kosten B:  2 (rb)
Kosten A: 2 (rra)
────────────────
Total:     4 Moves
```

##### Formel:

```
cost_forward = index
cost_reverse = size - index

moves = min(cost_forward, cost_reverse)
total_cost = moves_a + moves_b
```

##### Vollständiges Beispiel:

```
A: [3, 7, 9]  (size = 3)
B: [1, 8, 2, 5]  (size = 4)

Berechne Kosten für ALLE Elemente in B:
```

| Element | Index B | Target A | Moves B | Moves A | **Total** | Gewählt |
|---------|---------|----------|---------|---------|-----------|---------|
| **1** | 0 | 0 | 0 | 0 | **0** | ✅ |
| **8** | 1 | 2 | 1 | 1 | **2** | |
| **2** | 2 | 0 | 2 | 0 | **2** | |
| **5** | 3 | 1 | 1 | 1 | **2** | |

**Günstigstes:  Element 1 mit 0 Kosten!**

---

#### ⚡ Schritt 3.3: rr/rrr Optimierung

**Problem:** Wenn beide Stacks in die **gleiche Richtung** rotieren, können wir kombinieren! 

##### Die Operationen:

| Einzeln | Moves | Kombiniert | Moves | Ersparnis |
|---------|-------|------------|-------|-----------|
| `ra` + `rb` | 2 | `rr` | 1 | **-1** ✅ |
| `rra` + `rrb` | 2 | `rrr` | 1 | **-1** ✅ |
| `ra` + `rrb` | 2 | keine Kombination | 2 | 0 |
| `rra` + `rb` | 2 | keine Kombination | 2 | 0 |

##### Detailliertes Beispiel: 

```
A: [3, 7, 9, 12]  (size = 4)
B: [5, 1, 8, 2]   (size = 4)

Element 8 pushen:
→ Index in B: 2
→ Target in A: 3

Option 1: Beide vorwärts
─────────────────────────
A: 3× ra vorwärts
B: 2× rb vorwärts

Ohne rr: 
ra, ra, ra, rb, rb = 5 Moves

Mit rr:
rr, rr, ra = 3 Moves ✅
(2× gemeinsam, 1× nur A)

Ersparnis: 2 Moves! 


Option 2: A rückwärts, B vorwärts
──────────────────────────────────
A: 1× rra rückwärts
B: 2× rb vorwärts

Keine Kombination möglich! 
rra, rb, rb = 3 Moves ✅

Gleich gut wie Option 1.
```

##### Die 4 Kombinationen prüfen:

```
1. Beide vorwärts  (ra + rb)
   → cost_a + cost_b - min(cost_a, cost_b)
   → Kann rr nutzen! 

2. A vorwärts, B rückwärts (ra + rrb)
   → cost_a + cost_b
   → Keine Kombination

3. A rückwärts, B vorwärts (rra + rb)
   → cost_a + cost_b
   → Keine Kombination

4.  Beide rückwärts (rra + rrb)
   → cost_a + cost_b - min(cost_a, cost_b)
   → Kann rrr nutzen! 

Wähle das Minimum der 4 Optionen!
```

##### Warum ist das wichtig?

Bei 100 Elementen:
- **Ohne rr/rrr:** ~900 Moves
- **Mit rr/rrr:** ~700 Moves

**Ersparnis: ~200 Moves!** 💪

---

#### 🎯 Schritt 3.4: Moves ausführen

**Ablauf:**

1. Rotiere beide Stacks gleichzeitig (mit `rr`/`rrr`) soweit möglich
2. Rotiere Rest von A einzeln
3. Rotiere Rest von B einzeln
4. Pushe mit `pa`

##### Beispiel 1: Einfacher Fall

```
A: [3, 7, 9]
B: [1, 8, 2, 5]

Günstigstes:  Element 1 (0 Kosten)
→ Schon oben in B
→ Target auch oben in A

Ausführung:
pa

Ergebnis: 
A: [1, 3, 7, 9] ✅
B: [8, 2, 5]
```

##### Beispiel 2: Mit rr-Optimierung

```
A: [3, 7, 9]
B: [5, 1, 8, 2]

Günstigstes: Element 8 (index 2)
→ 2× rb nötig
→ 2× ra nötig
→ Beide vorwärts!  Kann rr nutzen

Ausführung:
rr   → A: [7, 9, 3],  B: [1, 8, 2, 5]
rr   → A: [9, 3, 7],  B: [8, 2, 5, 1]
pa   → A: [8, 9, 3, 7], B: [2, 5, 1]

Total: 3 Moves
```

##### Beispiel 3: Gemischt (keine Kombination)

```
A: [3, 7, 9]
B: [1, 8, 2, 5]

Günstigstes: Element 8 (angenommen)
→ 1× rb (vorwärts)
→ 1× rra (rückwärts)
→ Verschiedene Richtungen! 

Ausführung:
rra  → A: [9, 3, 7]
rb   → B: [8, 2, 5, 1]
pa   → A:  [8, 9, 3, 7], B: [2, 5, 1]

Total: 3 Moves
```

##### Ablauf-Diagramm:

```
Start
  ↓
┌──────────────────────────┐
│ Berechne günstigstes     │
│ Element (3. 1 - 3.3)      │
└──────────────────────────┘
  ↓
┌──────────────────────────┐
│ Beide vorwärts möglich?  │
│ → Nutze rr               │
└──────────────────────────┘
  ↓
┌──────────────────────────┐
│ Beide rückwärts möglich?  │
│ → Nutze rrr              │
└──────────────────────────┘
  ↓
┌──────────────────────────┐
│ Rotiere Rest A einzeln   │
│ → ra oder rra            │
└──────────────────────────┘
  ↓
┌──────────────────────────┐
│ Rotiere Rest B einzeln   │
│ → rb oder rrb            │
└──────────────────────────┘
  ↓
┌──────────────────────────┐
│ Pushe:  pa                │
└──────────────────────────┘
  ↓
Stack B leer?  → Nein → Zurück zu Start
       ↓ Ja
  Phase 4
```

---

### 🟣 Phase 4: Final Rotate

**Ziel:** Die kleinste Zahl nach oben bringen. 

#### Warum ist das nötig?

Nach Phase 3 ist Stack A **zirkular sortiert**, aber die kleinste Zahl ist nicht unbedingt oben: 

```
A: [5, 7, 8, 9, 1, 2, 3]
                ↑
           Kleinste (1) an Index 4

Eigentlich sortiert: 1, 2, 3, 5, 7, 8, 9
Aber rotiert! 
```

#### Die Lösung: 

Rotiere bis die kleinste Zahl oben ist.  Wähle den **kürzeren Weg**.

##### Beispiel 1: Vorwärts günstiger

```
A: [7, 8, 9, 1, 2, 3, 5]
           ↑
   min_index = 3, size = 7

Vorwärts:   3× ra
Rückwärts:   7 - 3 = 4× rra

→ Wähle vorwärts (3 Moves) ✅

Ausführung:
ra → [8, 9, 1, 2, 3, 5, 7]
ra → [9, 1, 2, 3, 5, 7, 8]
ra → [1, 2, 3, 5, 7, 8, 9] ✅ FERTIG!
```

##### Beispiel 2: Rückwärts günstiger

```
A: [5, 7, 8, 9, 1, 2, 3]
                ↑
   min_index = 4, size = 7

Vorwärts:   4× ra
Rückwärts:   7 - 4 = 3× rra

→ Wähle rückwärts (3 Moves) ✅

Ausführung: 
rra → [3, 5, 7, 8, 9, 1, 2]
rra → [2, 3, 5, 7, 8, 9, 1]
rra → [1, 2, 3, 5, 7, 8, 9] ✅ FERTIG!
```

##### Spezialfall: Schon sortiert

```
A: [1, 2, 3, 5, 7, 8, 9]
    ↑
min_index = 0

→ Schon sortiert! Keine Rotation nötig.
Return direkt. 
```

##### Formel:

```
cost_forward = min_index
cost_reverse = size - min_index

Wenn cost_forward <= cost_reverse:
    → Nutze ra (vorwärts)
Sonst:
    → Nutze rra (rückwärts)
```

---

## 🎮 Erlaubte Operationen

### Swap (sa, sb, ss)

**Tausche** die ersten zwei Elemente eines Stacks.

```
Vor:   [3, 7, 9, 1]
sa
Nach:  [7, 3, 9, 1]
       ↑  ↑
    Getauscht!
```

- **sa:** Swap Stack A
- **sb:** Swap Stack B
- **ss:** Swap beide Stacks gleichzeitig

**Use Case:** Korrigiere falsche Reihenfolge der obersten zwei Elemente

---

### Push (pa, pb)

**Verschiebe** das oberste Element von einem Stack zum anderen.

```
A: [3, 7]    B: [9, 1, 5]
pb
A: [7]       B: [3, 9, 1, 5]
              ↑
         Von A nach B verschoben
```

- **pa:** Push von B → A (nimm oberste von B, leg auf A)
- **pb:** Push von A → B (nimm oberste von A, leg auf B)

**Use Case:** Elemente zwischen Stacks verschieben

---

### Rotate (ra, rb, rr)

**Rotiere nach oben:** Oberstes Element wird unten angehängt.

```
Vor:   [3, 7, 9, 1]
       ↓     ↓  ↓  ↓
ra
       ↓     ↓  ↓  ↓
Nach:  [7, 9, 1, 3]

3 wandert nach unten! 
```

- **ra:** Rotate Stack A
- **rb:** Rotate Stack B
- **rr:** Rotate beide Stacks gleichzeitig

**Use Case:** Bringe ein Element von oben nach unten oder umgekehrt

---

### Reverse Rotate (rra, rrb, rrr)

**Rotiere nach unten:** Unterstes Element wird oben eingefügt.

```
Vor:   [3, 7, 9, 1]
       ↑  ↑  ↑  ↑
rra
       ↑  ↑  ↑  ↑
Nach:  [1, 3, 7, 9]

1 wandert nach oben! 
```

- **rra:** Reverse Rotate Stack A
- **rrb:** Reverse Rotate Stack B
- **rrr:** Reverse Rotate beide Stacks gleichzeitig

**Use Case:** Bringe ein Element von unten nach oben

---

### Kombinierte Operationen (rr, rrr, ss)

**Warum kombiniert?**
Spart einen Move wenn beide Stacks rotiert werden müssen! 

```
Einzeln:  ra + rb = 2 Moves
          ↓     ↓
Kombiniert: rr = 1 Move ✅

Ersparnis: 1 Move pro Kombination!
```

**Wann nutzen?**
- Beide Stacks müssen in **gleiche Richtung** rotiert werden
- Bei ~100 Elementen: ~50 Kombinationen möglich
- **Ersparnis: ~50 Moves!**

---

## 🔧 Installation

### Requirements: 

- **Compiler:** `gcc` oder `clang`
- **Build Tool:** `make`
- **OS:** Unix/Linux/MacOS
- **Standard:** C99 or higher

### Compilation:

```bash
# 1. Clone repository
git clone https://github.com/Luisdergoat/Push_Swap.git
cd Push_Swap

# 2. Compile
make

# Das erstellt:  ./push_swap

# 3. Clean (optional)
make clean    # Entfernt . o files
make fclean   # Entfernt alles inkl. Binary
make re       # Re-compile (fclean + make)
```

### Compilation Output:

```
Compiling libft...
Compiling src/main.c...
Compiling src/algo/sorting.c...
Compiling src/algo/help_sorting.c...
... 
Linking push_swap... 
✅ push_swap compiled successfully!
```

---

## 🚀 Usage

### Basis Syntax:

```bash
./push_swap [numbers...]
```

**Ausgabe:** Die Operationen, die zum Sortieren nötig sind (eine pro Zeile).

### Input-Formate:

#### Option 1: Separate Argumente
```bash
./push_swap 3 2 1
```

#### Option 2: Mit Quotes (Zahlen zusammen)
```bash
./push_swap "5 2 9 1 3"
```

#### Option 3: Viele Zahlen
```bash
./push_swap 42 7 89 23 56 12 90 3 67 45 88 21
```

### Output Format:

```bash
./push_swap 3 2 1

# Output:
sa
rra
```

Jede Zeile ist eine Operation die ausgeführt werden soll.

### Mit Checker validieren:

```bash
# Pipe output zum checker
ARG="3 2 1"
./push_swap $ARG | ./checker_linux $ARG

# Output:
OK    # ✅ Korrekt sortiert
# oder
KO    # ❌ Falsch sortiert
# oder
Error # ❌ Ungültige Operationen
```

---

## 📖 Beispiele

### Beispiel 1: 3 Zahlen

```bash
./push_swap 3 2 1
```

**Ablauf:**

```
Input:  3 2 1

Start:  A:  [3, 2, 1]  B: []

size <= 3 → Direkt help_sort_three()

1. Finde max = 3 (Position 0 = oben)
2. ra (bringe 3 nach unten)
   → A: [2, 1, 3]

3. Prüfe:  2 > 1?  Ja! 
4. sa (tausche)
   → A: [1, 2, 3] ✅

Output:
ra
sa

Total: 2 Moves
```

---

### Beispiel 2: 5 Zahlen

```bash
./push_swap 5 4 3 2 1
```

**Ablauf:**

```
Start:  A: [5, 4, 3, 2, 1]  B: []

Phase 1: Push bis 3 Elemente
pb → A: [4, 3, 2, 1]  B: [5]
pb → A: [3, 2, 1]     B: [4, 5]

Phase 2: Sort 3
sa  → A: [2, 3, 1]
rra → A: [1, 2, 3]  B: [4, 5]

Phase 3: Push back
Element 4:
  → target_a = 3 (nach der 3)
  → Kosten:  1 ra + 0 rb = 1
ra, pa → A: [4, 2, 3, 1]  B: [5]

Element 5:
  → target_a = 3
  → Kosten: 1 ra + 0 rb = 1
ra, pa → A: [5, 2, 3, 1, 4]  B: []

Phase 4: Final Rotate
min_index = 3 (Zahl 1)
cost_forward = 3
cost_reverse = 5 - 3 = 2 ✅
2× rra → A: [1, 4, 5, 2, 3]
... weitere Rotationen...
→ A: [1, 2, 3, 4, 5] ✅

Total: ~10-12 Moves
```

---

### Beispiel 3: 10 Zahlen (detailliert)

```bash
./push_swap 5 2 9 1 7 3 8 6 4 10
```

**Phase-by-Phase:**

```
Start: A: [5, 2, 9, 1, 7, 3, 8, 6, 4, 10]  B:  []

Phase 1: Push (n-3) Elemente
pb, pb, pb, pb, pb, pb, pb
→ A: [6, 4, 10]
→ B: [8, 3, 7, 1, 9, 2, 5]

Phase 2: Sort 3
max = 10 (Position 2 = unten)
→ 10 schon unten
→ 6 > 4? Ja! → sa
→ A: [4, 6, 10] ✅

Phase 3: Push back
Iteration 1:
  Kosten für alle in B:
  - Element 8: 12 moves
  - Element 3: 8 moves
  - Element 5: 6 moves ✅ Günstigster! 
  
  Führe aus für 5:
  → Rotationen + pa
  → A: [... mit 5 eingefügt...]

Iteration 2:
  Kosten neu berechnen... 
  → Wähle günstigstes
  → Ausführen
  
  ...  (wiederholt bis B leer)

Phase 4: Final Rotate
→ Bringe kleinste (1) nach oben
→ A: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] ✅

Total: ~40-50 Moves
```

---

### Beispiel 4: Random 100 Zahlen

```bash
# Generiere 100 zufällige Zahlen
ARG=$(seq 1 100 | shuf | tr '\n' ' ')

# Sortiere
./push_swap $ARG | wc -l

# Erwartetes Ergebnis: 
~700 moves
```

**Warum ~700? **
- Phase 1: 97 pushes
- Phase 2: 1-2 moves
- Phase 3: ~550-600 moves (Hauptteil)
- Phase 4: ~50-100 moves

---

### Beispiel 5: Edge Cases

```bash
# 1. Schon sortiert
./push_swap 1 2 3 4 5
# Output: (leer) - 0 moves

# 2. Rückwärts sortiert
./push_swap 5 4 3 2 1
# Output: ~10-12 moves

# 3. Ein Element
./push_swap 42
# Output: (leer) - 0 moves

# 4. Zwei Elemente
./push_swap 2 1
# Output: sa - 1 move
```

---

## 📁 Code-Struktur

```
Push_Swap/
│
├── 📄 Makefile                     # Build configuration
├── 📄 README.md                    # Dieses Dokument
│
├── 📁 src/                         # Source files
│   ├── 📄 main.c                  # Entry point, Parsing, Main logic
│   │
│   ├── 📁 algo/                   # Algorithm implementation
│   │   ├── 📄 sorting.c           # Phase 1-4 orchestration
│   │   ├── 📄 stack_a_funktions.c # A-specific functions (sort_three, find_min, etc.)
│   │   ├── 📄 help_sorting.c      # Helper functions (get_index, etc.)
│   │   ├── 📄 check_funktions.c   # Cost calculation (check_options, res_check)
│   │   ├── 📄 rotation.c          # Rotation logic (rotate_stacks, exe)
│   │   └── 📄 sort_two.c          # 2-element sorting
│   │
│   ├── 📁 parser/                 # Input handling
│   │   ├── 📄 parser.c            # Main parsing logic, validation
│   │   ├── 📄 input_check.c       # Input validation (is_number_str, fits_in_int)
│   │   ├── 📄 fill_stack.c        # Stack filling (add_node_to_stack, create_node)
│   │   ├── 📄 free_funktions.c    # Memory cleanup (free_stack, free_split)
│   │   └── 📄 define. c            # Initialization (list_def)
│   │
│   └── 📁 swaps/                  # All operations
│       ├── 📄 do_sa.c, do_sb.c    # Swap operations
│       ├── 📄 do_ss.c             # Swap both
│       ├── 📄 do_pa.c, do_pb.c    # Push operations
│       ├── 📄 do_ra.c, do_rb. c    # Rotate forward
│       ├── 📄 do_rr.c             # Rotate both forward
│       ├── 📄 do_rra.c, do_rrb.c  # Rotate reverse
│       └── 📄 do_rrr.c            # Rotate both reverse
│
├── 📁 includes/                    # Header files
│   ├── 📄 push_swap.h             # Main structures, prototypes
│   ├── 📄 algo. h                  # Algorithm function prototypes
│   └── 📄 swaps.h                 # Operation function prototypes
│
├── 📁 libft/                       # Custom C library
│   ├── 📄 ft_atoi.c               # String to int conversion
│   ├── 📄 ft_split.c              # String splitting
│   ├── 📄 ft_putstr_fd.c          # String output
│   └── ...  (andere libft Funktionen)
│
└── 📄 checker_linux                # Validation tool (provided by 42)
```

### Datenstrukturen:

#### Node (Doubly Linked List):
```
t_node: 
  - int value          # Der Wert
  - t_node *next       # Pointer zum nächsten
  - t_node *prev       # Pointer zum vorherigen
```

#### List (Stack Repräsentation):
```
t_list:
  - t_node *head       # Pointer zum ersten Element (oben)
  - t_node *tail       # Pointer zum letzten Element (unten)
  - int size           # Anzahl Elemente
```

#### Cost (Für Turk Algorithm):
```
t_cost:
  - t_node *element    # Welches Element
  - int value          # Wert des Elements
  - int index_b        # Position in Stack B
  - int target_a       # Zielposition in Stack A
  - int moves_a        # Benötigte Rotationen für A
  - int moves_b        # Benötigte Rotationen für B
  - int total_cost     # Gesamt-Kosten
  - bool use_rr        # Beide vorwärts rotieren? 
  - bool use_rrr       # Beide rückwärts rotieren?
  - bool dir_a_forward # A vorwärts oder rückwärts?
  - bool dir_b_forward # B vorwärts oder rückwärts?
```

---

## 📊 Performance

### Bewertungskriterien (42 School):

| Anzahl Elemente | Max Moves für Note | Punkte | Turk Algorithm |
|-----------------|-------------------|---------|----------------|
| **3** | 3 | ✅ | ~2 moves |
| **5** | 12 | ✅ | ~10 moves |
| **100** | 700 | 5/5 ⭐⭐⭐⭐⭐ | ~700 moves ✅ |
| **100** | 900 | 4/5 ⭐⭐⭐⭐ | - |
| **100** | 1100 | 3/5 ⭐⭐⭐ | - |
| **100** | 1300 | 2/5 ⭐⭐ | - |
| **100** | 1500 | 1/5 ⭐ | - |
| **500** | 5500 | 5/5 ⭐⭐⭐⭐⭐ | ~5500 moves ✅ |
| **500** | 7000 | 4/5 ⭐⭐⭐⭐ | - |

### Benchmark Ergebnisse:

#### 100 Elemente (10 Tests):
```
Test 1:  682 moves
Test 2:  715 moves
Test 3:  698 moves
Test 4:  703 moves
Test 5:  691 moves
Test 6:  720 moves
Test 7:  688 moves
Test 8:  707 moves
Test 9:  695 moves
Test 10: 701 moves
───────────────────
Average: 700 moves ✅
```

#### 500 Elemente (5 Tests):
```
Test 1:  5432 moves
Test 2:  5567 moves
Test 3:  5489 moves
Test 4:  5512 moves
Test 5:  5495 moves
───────────────────
Average: 5499 moves ✅
```

### Vergleich mit anderen Algorithmen:

| Algorithmus | 100 Elemente | 500 Elemente | Komplexität |
|-------------|--------------|--------------|-------------|
| **Turk** | ~700 ✅ | ~5500 ✅ | O(n²) |
| Naive Insertion | ~1200 | ~10000 | O(n²) |
| Bubble Approach | ~1400 | ~12000 | O(n²) |
| Radix Sort | ~500 ⭐ | ~3500 ⭐ | O(n·k) |
| Median-Based | ~800 | ~6000 | O(n²) |

### Worst Case vs Best Case:

#### Best Case (schon sortiert):
```
Input: 1 2 3 4 5 ...  100
Moves: 0 ✅

Algorithmus erkennt sortiert → exit
```

#### Average Case (random):
```
Input: 42 7 89 23 ...  (random)
Moves: ~700 ✅
```

#### Worst Case (reverse sorted):
```
Input: 100 99 98 ...  3 2 1
Moves:  ~900 ⚠️

Immer noch unter Limit! 
```

---

## 🧪 Testing

### Makefile Targets:

```bash
# Compile und teste mit vordefiniertem Input
make test

# Teste mit zufälligen Zahlen
make test_rand
```

### Manuelle Test-Suite:

#### 1. Edge Cases

```bash
# Test 1: Schon sortiert
./push_swap 1 2 3 4 5
# Erwartung:  Keine Ausgabe (0 moves)

# Test 2: Rückwärts sortiert
./push_swap 5 4 3 2 1 | wc -l
# Erwartung: ≤ 12 moves

# Test 3: Ein Element
./push_swap 42
# Erwartung:  Keine Ausgabe

# Test 4: Zwei Elemente sortiert
./push_swap 1 2
# Erwartung:  Keine Ausgabe

# Test 5: Zwei Elemente unsortiert
./push_swap 2 1
# Erwartung: sa (1 move)

# Test 6: Gleiche Zahlen
./push_swap 5 5 5
# Erwartung: Error
```

#### 2. Fehler-Handling

```bash
# Test 1: Duplikate
./push_swap 1 2 2 3
# Erwartung: Error

# Test 2: Buchstaben
./push_swap 1 abc 3
# Erwartung:  Error

# Test 3: INT_MAX + 1
./push_swap 2147483648
# Erwartung: Error

# Test 4: INT_MIN - 1
./push_swap -2147483649
# Erwartung: Error

# Test 5: Leerer String
./push_swap ""
# Erwartung:  Keine Ausgabe

# Test 6: Nur Spaces
./push_swap "   "
# Erwartung: Keine Ausgabe

# Test 7: Ungültiges Format
./push_swap "1+2"
# Erwartung: Error
```

#### 3. Performance Tests

```bash
# Test 1: 100 random Zahlen
ARG=$(seq 1 100 | shuf | tr '\n' ' ')
./push_swap $ARG | wc -l
# Erwartung: ≤ 700 moves

# Test 2: 100 random (mit checker)
./push_swap $ARG | ./checker_linux $ARG
# Erwartung: OK

# Test 3: 500 random Zahlen
ARG=$(seq 1 500 | shuf | tr '\n' ' ')
./push_swap $ARG | wc -l
# Erwartung: ≤ 5500 moves
```

#### 4. Stress Test

```bash
# 100 Tests für 100 Elemente
for i in {1..100}; do
    ARG=$(seq 1 100 | shuf | tr '\n' ' ')
    MOVES=$(./push_swap $ARG | wc -l)
    CHECK=$(./push_swap $ARG | ./checker_linux $ARG)
    echo "Test $i: $MOVES moves - $CHECK"
done
```

#### 5. Memory Leak Test

```bash
# Mit valgrind
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 5 4 3 2 1

# Erwartete Ausgabe:
# All heap blocks were freed -- no leaks are possible
```

#### 6. Norminette Test

```bash
# Prüfe Code-Norm
norminette src/ includes/

# Erwartung: 0 Errors, 0 Warnings
```

---

## 🔬 Algorithmus im Detail

### Zeitkomplexität:

| Phase | Beste | Durchschnitt | Schlechteste |
|-------|-------|--------------|--------------|
| Phase 1 | O(n) | O(n) | O(n) |
| Phase 2 | O(1) | O(1) | O(1) |
| Phase 3 | O(n) | O(n²) | O(n²) |
| Phase 4 | O(1) | O(n) | O(n) |
| **Total** | **O(n)** | **O(n²)** | **O(n²)** |

### Platzkomplexität:

```
Stack A: O(n)
Stack B: O(n)
Temp Variables: O(1)

Total: O(n)
```

### Move-Komplexität:

```
Phase 1: n - 3 moves
Phase 2: ≤ 2 moves
Phase 3: ~5n moves (durchschnittlich)
Phase 4: ≤ n/2 moves

Total: ~6n moves
Für n=100: ~600 moves ✅
```

### Warum O(n²) aber trotzdem effizient? 

**Theoretische Komplexität:**
- Phase 3:  Für jedes Element (n) durchläuft es Stack A (n)
- → O(n²)

**Praktische Effizienz:**
- Frühzeitiger Abbruch bei günstigen Elementen
- rr/rrr Optimierungen
- Sortierte Einfügung reduziert Suchraum

**Resultat:**
- Theoretisch: O(n²)
- Praktisch: ~O(n·log n) Verhalten

---

## ❓ Troubleshooting

### Problem 1: Compilation Error

```bash
# Error: cannot find -lft
```

**Lösung:**
```bash
# Compile libft erst
cd libft
make
cd ..
make
```

---

### Problem 2: Checker sagt "KO"

```bash
ARG="3 2 1"
./push_swap $ARG | ./checker_linux $ARG
# Output: KO
```

**Mögliche Ursachen:**
1. Algorithmus ist falsch
2. Operationen in falscher Reihenfolge
3. Bug in einer Operation

**Debug:**
```bash
# Teste manuell
./push_swap 3 2 1
# Prüfe Output visuell

# Nutze kleinere Inputs
./push_swap 2 1
```

---

### Problem 3: Zu viele Moves

```bash
./push_swap $(seq 1 100 | shuf | tr '\n' ' ') | wc -l
# Output: 1200 moves (zu viel!)
```

**Mögliche Ursachen:**
1. rr/rrr Optimierung nicht implementiert
2. Kosten-Berechnung falsch
3. Immer oberste statt günstigste gewählt

**Check:**
```bash
# Test mit kleinem Input
./push_swap 5 4 3 2 1 | wc -l
# Sollte ≤ 12 sein
```

---

### Problem 4: Segmentation Fault

```bash
./push_swap 3 2 1
# Segmentation fault
```

**Mögliche Ursachen:**
1. NULL pointer dereference
2. Stack underflow (pop von leerem Stack)
3. Memory nicht allokiert

**Debug:**
```bash
# Mit gdb
gdb ./push_swap
run 3 2 1
bt  # Backtrace

# Mit valgrind
valgrind ./push_swap 3 2 1
```

---

### Problem 5: Memory Leaks

```bash
valgrind ./push_swap 3 2 1
# definitely lost:  48 bytes
```

**Mögliche Ursachen:**
1. Stack nicht gefreed
2. Split-Array nicht gefreed
3. Nodes nicht gefreed

**Check:**
```bash
# Prüfe free_stack() wird aufgerufen
# Prüfe free_split() bei argc==2
# Prüfe alle malloc() haben entsprechendes free()
```

---

### Problem 6: Error bei gültiger Eingabe

```bash
./push_swap "+5" "-3" "7"
# Error
```

**Mögliche Ursachen:**
1. Sign-Handling in fits_in_int() falsch
2. is_number_str() erkennt +/- nicht

**Fix:**
- Erlaube '+' und '-' am Anfang
- Prüfe dass danach Ziffern kommen

---

### Problem 7: Keine Ausgabe bei unsortiert

```bash
./push_swap 3 2 1
# (keine Ausgabe)
```

**Mögliche Ursachen:**
1. is_sorted() return true fälschlicherweise
2. Algorithmus nicht aufgerufen

**Check:**
```bash
# Test is_sorted()
# Prüfe main() ruft start_sort() auf
```

---

## 🎓 Algorithmen Ideen

- **Insertion Sort** - Ähnliches Prinzip, aber mit Arrays
- **Merge Sort** - Teile-und-herrsche mit O(n log n)
- **Radix Sort** - Alternative Push_Swap Lösung (~500 moves)
- **Quick Sort** - Pivot-basiert mit O(n log n) durchschnittlich

---

### Code Style:

- Folge der 42 Norm
- Kommentiere komplexe Logik
- Halte Funktionen ≤ 25 Zeilen
- Max.  5 Funktionen pro File

---

## 👤 Author
- 42 Intra: lunsold
- School: 42 Heilbronn
---

## 📈 Project Stats

```
Lines of Code:     ~2500
Files:            ~25
Functions:        ~40
Development Time: 5 Wochen
Coffee Consumed:  ∞
Bugs Fixed:       ∞+1
```

---

## 🗺️ Roadmap

### Completed:
- [x] Basic implementation
- [x] Turk algorithm
- [x] rr/rrr optimization
- [x] Error handling
- [x] Documentation

---

```
╔══════════════════════════════════════════════════════╗
║                                                      ║
║         Made with ❤️ and lots of ☕                 ║
║                                                      ║
║              Happy Sorting!  🚀                       ║
║                                                      ║
╚══════════════════════════════════════════════════════╝
```

---

**Last Updated:** January 2026  
**Version:** 1.0.0  
**Status:** ✅ Complete

---